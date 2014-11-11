#include "Personaje.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

Personaje::Personaje()
{
    frame=0;
}

Personaje::~Personaje()
{
    //dtor
}

void Personaje::logic(Uint8* teclas_presionadas)
{
    std::cout<<"Test"<<std::endl;
}

void Personaje::render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, *textura_actual, NULL, &rectangulo);

    if(frame%5==0)//25
        textura_actual++;
    if(orientacion=="down")
    {
        if(textura_actual==texturas_down.end())
            textura_actual=texturas_down.begin();
    }

    if(orientacion=="up")
    {
        if(textura_actual==texturas_up.end())
            textura_actual=texturas_up.begin();
    }

    if(orientacion=="left")
    {
        if(textura_actual==texturas_left.end())
        {
            textura_actual=texturas_left.begin();
        }
    }

    if(orientacion=="right")
    {
        if(textura_actual==texturas_right.end())
        {
            textura_actual=texturas_right.begin();
        }
    }
    frame++;
}

bool Personaje::colision(SDL_Rect r1, SDL_Rect r2)
{
    return r1.x + r1.w > r2.x  &&  r1.x < r2.x + r2.w
            && r1.y + r1.h > r2.y && r1.y < r2.y + r2.h;
}

void Personaje::destroy_textures()
{
    for(textura_actual = texturas_down.begin(); textura_actual != texturas_down.end(); textura_actual++)
    {
        SDL_DestroyTexture(*textura_actual);
    }

    for(textura_actual = texturas_up.begin(); textura_actual != texturas_down.end(); textura_actual++)
    {
        SDL_DestroyTexture(*textura_actual);
    }

    for(textura_actual = texturas_left.begin(); textura_actual != texturas_down.end(); textura_actual++)
    {
        SDL_DestroyTexture(*textura_actual);
    }

    for(textura_actual = texturas_right.begin(); textura_actual != texturas_down.end(); textura_actual++)
    {
        SDL_DestroyTexture(*textura_actual);
    }

    for(textura_actual = texturas_ataque.begin(); textura_actual != texturas_down.end(); textura_actual++)
    {
        SDL_DestroyTexture(*textura_actual);
    }
}
