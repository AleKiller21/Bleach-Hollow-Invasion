#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <list>
#include <stdlib.h>
#include "Personaje.h"
#include "PersonajeJugador.h"
#include "NPC.h"
#include "Hollow.h"
#include "Hollow2.h"
#include "Hollow3.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*game_background, *credits_background, *text_texture;
SDL_Rect rect_background,rect_character, rect_text;

TTF_Font * font;
SDL_Color text_color = {0,0,0};
SDL_Surface * text;

Personaje p;
int frame=0;
int segundos = 0;
int w=0,h=0;
bool wave1_complete = false;
bool wave2_complete = false;
bool dialogs1 = true;
bool * wave_apuntador = NULL;
bool esc = false;
list<Personaje*>personajes;
list<SDL_Texture*>dialogo_texturas;
list<SDL_Texture*>::iterator dialogo_actual;
list<SDL_Texture*> creditos_texturas;

void show_dialogs()
{
    while(dialogo_actual != dialogo_texturas.end())
    {
        SDL_RenderCopy(renderer, game_background, NULL, &rect_background);
        SDL_RenderCopy(renderer, *dialogo_actual, NULL, &rect_text);
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_RETURN)
                {
                    dialogo_actual++;
                }
            }
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
        }
    }
}

void waves(int numwave)
{
    if(numwave == 1)
    {
        wave_apuntador = &wave1_complete;
        show_dialogs();
    }
    else if(numwave == 2)
        wave_apuntador = &wave2_complete;

    while((*wave_apuntador) != true)
    {
        segundos++;
        //cout << "Segundos: " << segundos << endl;
        frame++;
        if(frame%100==0)
        {
            if(numwave == 1)
                personajes.push_back(new Hollow (rand()%880,rand() % 570,renderer,&personajes));

            else if(numwave == 2)
            {
                personajes.push_back(new Hollow2 (rand()%880,rand() % 570,renderer,&personajes));
                personajes.push_back(new Hollow3 (rand()%880,rand() % 570,renderer,&personajes));
            }
        }
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    esc = true;
                    return;
                }
            }
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
        }

        for(list<Personaje*>::iterator i = personajes.begin(); i!=personajes.end(); i++)
        {
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));
            if((*i)->id == "Personaje")
            {
                if((*i)->HP == 0)
                {
                    (*i)->reset();
                    return;
                }

                else if((*i)->contador_puntos == 400)//100
                {
                    *wave_apuntador = true;
                    (*i)->reset();
                }
            }
        }

        SDL_RenderCopy(renderer, game_background, NULL, &rect_background);
        //SDL_RenderCopy(renderer, *dialogo_actual, NULL, &rect_text);

        for(list<Personaje*>::iterator i = personajes.begin(); i!=personajes.end(); i++)
            (*i)->render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(16.66);

        if(segundos == 2300 && (*wave_apuntador) != true)//800
        {
            esc = true;
            return;
        }
    }
}

void wave2()
{
    segundos = 0;
    SDL_DestroyTexture(game_background);
    game_background = IMG_LoadTexture(renderer, "assets/Bleach/stage2.png");
    SDL_RenderCopy(renderer, game_background, NULL, &rect_background);
    frame = 0;
    waves(2);
}

void loopGame()
{
    waves(1);
    if(esc != true)
        wave2();
}

void credits()
{
    while(dialogo_actual != creditos_texturas.end())
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return;
                }
            }
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
        }

        if(frame%20 == 0)
        {
            rect_text.y--;
            if(rect_text.y == 250)
            {
                rect_text.y = 500;
                dialogo_actual++;
                if(dialogo_actual == creditos_texturas.end())
                    break;
            }
        }
        frame++;

        SDL_RenderCopy(renderer, credits_background, NULL, &rect_background);
        SDL_RenderCopy(renderer, *dialogo_actual, NULL, &rect_text);
        SDL_RenderPresent(renderer);
    }
}

void loopMenu()
{
    int mouse_x;
    int mouse_y;
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                cout << "Adios" << endl;
                return;
            }

            if(Event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&mouse_x, &mouse_y);
                if((mouse_x >= 248 && mouse_x <= 542) && (mouse_y >= 298 && mouse_y <= 369))
                {
                    cout << "START!" << endl;
                    rect_text.y = 500;
                    segundos = 0;
                    wave1_complete = false;
                    wave2_complete = false;
                    dialogo_actual = dialogo_texturas.begin();
                    frame = 0;
                    game_background = IMG_LoadTexture(renderer, "assets/Bleach/stage_night - Copy.png");
                    loopGame();
                }

                if((mouse_x >= 245 && mouse_x <= 538) && (mouse_y >= 382 && mouse_y <= 456))
                {
                    dialogo_actual = creditos_texturas.begin();
                   credits();
                }

                if((mouse_x >= 256 && mouse_x <= 537) && (mouse_y >= 487 && mouse_y <= 561))
                {
                    return;
                }
            }
        }
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

SDL_Surface * setText(int pos)
{
    switch(pos)
    {
    case 1:
        return TTF_RenderText_Solid(font, "Ichigo: Hirako! What have you done?!", text_color);

    case 2:
        return TTF_RenderText_Solid(font, "Hirako: This is your final test, Ichigo.", text_color);

    case 3:
        return TTF_RenderText_Solid(font, "Hirako: You'll have to use your hollow powers to defeat all those hollows.", text_color);

    case 4:
        return TTF_RenderText_Solid(font, "Hirako: Fail and all the humans in Karakura town will die.", text_color);

    case 5:
        return TTF_RenderText_Solid(font, "Ichigo: Damned you!", text_color);

    case 6:
        return TTF_RenderText_Solid(font, "Hirako: This should bring you back memories of when you first encounter your friend Ishida. Now go!", text_color);

    case 7:
        return TTF_RenderText_Solid(font, "Hollow1: Neimad", text_color);

    case 8:
        return TTF_RenderText_Solid(font, "Ichigo left attack: Neo1146 ", text_color);

    case 9:
        return TTF_RenderText_Solid(font, "Hollow2: Ichigo-San", text_color);

    case 10:
        return TTF_RenderText_Solid(font, "Stage2: parrishbroadnax", text_color);

    case 11:
        return TTF_RenderText_Solid(font, "Stage1: JoonTH", text_color);

    case 12:
        return TTF_RenderText_Solid(font, "Ichigo's movement: Neimad & Yurestu", text_color);

    case 13:
        return TTF_RenderText_Solid(font, "Hollow3: Kionji", text_color);
    }
}

void load_dialog()
{
    font = TTF_OpenFont("ARLRDBD.ttf", 30);//30
    if(font == NULL)
    {
        cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        exit(0);
    }
    //text = TTF_RenderText_Solid(font, "Probando...", text_color);

    for(int i = 1; i < 7; i++)
    {
        text = setText(i);
        if(text == NULL)
        {
            TTF_Quit();
            cout << "No se cargo el dialogo" << endl;
        }

        text_texture = SDL_CreateTextureFromSurface(renderer, text);
        if(text_texture == NULL)
        {
            cout << "Fallo la conversion a textura" << endl;
        }

        dialogo_texturas.push_back(text_texture);
    }

    for(int i = 7; i < 14; i++)
    {
        text = setText(i);
        if(text == NULL)
        {
            TTF_Quit();
            cout << "No se cargo el dialogo" << endl;
        }

        text_texture = SDL_CreateTextureFromSurface(renderer, text);
        if(text_texture == NULL)
        {
            cout << "Fallo la conversion a textura" << endl;
        }

        creditos_texturas.push_back(text_texture);
    }

    dialogo_actual = dialogo_texturas.begin();

    SDL_QueryTexture(*dialogo_actual, NULL, NULL, &w, &h);
    rect_text.x = 10; rect_text.y = 500; rect_text.w = w; rect_text.h = h;
}

int main( int argc, char* args[] )
{
//Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    if(TTF_Init() != 0)
    {
        cout << "No se inicio TTF" << endl;
        exit(0);
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Bleach Hollow Invasion", 100, 100, 914/*WIDTH*/, 597/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }



    //Init textures





    background = IMG_LoadTexture(renderer,"assets/Bleach/Main_menu.png");
    game_background = IMG_LoadTexture(renderer, "assets/Bleach/stage_night - Copy.png");
    credits_background = IMG_LoadTexture(renderer, "assets/Bleach/Credits.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    load_dialog();
    //SDL_QueryTexture(text_texture, NULL, NULL, &w, &h);
    //rect_text.x = 100; rect_text.y = 500; rect_text.w = w; rect_text.h = h;

    SDL_RenderCopy(renderer, background, NULL, &rect_background);

    SDL_RenderPresent(renderer);

    personajes.push_back(new PersonajeJugador (0,0,renderer,&personajes));
    loopMenu();

    return 0;
}


