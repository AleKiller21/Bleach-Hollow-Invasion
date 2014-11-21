#include "PersonajeJugador.h"

PersonajeJugador::PersonajeJugador(int x, int y, SDL_Renderer* renderer, list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;

    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/stance.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);
    //texturas_down.push_back(textura);

    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/down1.png"));
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/down2.png"));
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/down3.png"));
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/down4.png"));
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/down5.png"));
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/down6.png"));
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/down7.png"));
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/down8.png"));

    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/up1.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/up2.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/up3.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/up4.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/up5.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/up6.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/up7.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/up8.png"));
    //texturas_up.push_back(textura);

    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/stance_left.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/left1.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/left2.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/left3.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/left4.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/left5.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/left6.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/left7.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/left8.png"));

    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/stance.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/right1.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/right2.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/right3.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/right4.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/right5.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/right6.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/right7.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/right8.png"));

    texturas_ataque.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/ataque/right1.png"));
    texturas_ataque.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/ataque/right2.png"));
    texturas_ataque.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/ataque/right3.png"));
    texturas_ataque.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/ataque/right4.png"));
    texturas_ataque.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/ataque/right5.png"));
    texturas_ataque.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/ataque/right6.png"));
    texturas_ataque.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo4/ataque/right7.png"));

    texturas_ataque_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/left1.png"));
    texturas_ataque_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/left2.png"));
    texturas_ataque_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/left3.png"));
    texturas_ataque_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/left4.png"));

    texturas_ataque_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/up1.png"));
    texturas_ataque_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/up2.png"));
    texturas_ataque_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/up3.png"));
    texturas_ataque_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/up4.png"));

    texturas_ataque_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/down1.png"));
    texturas_ataque_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/down2.png"));
    texturas_ataque_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/down3.png"));
    texturas_ataque_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/Ichigo3/ataque/down4.png"));

    orientacion="right";

    textura_actual=texturas_right.begin();
    contador_puntos = 0;
    HP = 200;
    id = "Personaje";
}

PersonajeJugador::~PersonajeJugador()
{
    //dtor
}

void PersonajeJugador::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;
    moviendo = false;

    if( teclas_presionadas[ SDL_SCANCODE_UP ] )
    {
        rectangulo.y-=10;
        moviendo = true;
        if(orientacion!="up")
            textura_actual=texturas_up.begin();
        orientacion="up";
    }

    if( teclas_presionadas[ SDL_SCANCODE_DOWN ])
    {
        rectangulo.y+=10;
         moviendo = true;
        if(orientacion!="down")
            textura_actual=texturas_down.begin();
        orientacion="down";
    }

    if( teclas_presionadas[ SDL_SCANCODE_RIGHT ] )
    {
        rectangulo.x+=10;
         moviendo = true;
        if(orientacion!="right")
            textura_actual=texturas_right.begin();
        orientacion="right";
    }

    if( teclas_presionadas[ SDL_SCANCODE_LEFT ] )
    {
        rectangulo.x-=10;
         moviendo = true;
        if(orientacion!="left")
            textura_actual=texturas_left.begin();
        orientacion="left";
    }

    if(teclas_presionadas[SDL_SCANCODE_F])
    {
        ataque = true;
        if(orientacion == "right")
            textura_actual = texturas_ataque.begin();
        else if(orientacion == "left")
            textura_actual = texturas_ataque_left.begin();
        else if(orientacion == "up")
            textura_actual = texturas_ataque_up.begin();
        else
            textura_actual = texturas_ataque_down.begin();
    }

    for(list<Personaje*>::iterator i = personajes->begin(); i!=personajes->end(); i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo) && ataque == true)
        {
            (*i)->destroy_textures();
            personajes->erase(i);
            contador_puntos+=20;
            cout << "Puntos acumulados: " << contador_puntos << endl;
            //break;
        }

        else if(colision(this->rectangulo, (*i)->rectangulo) && ataque != true)
        {
            rectangulo = temp;
            HP--;
            cout <<"HP: " << HP << endl;
        }
    }
}

void PersonajeJugador::render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, *textura_actual, NULL, &rectangulo);
    if(moviendo || ataque == true)
    {
        if(frame%5==0)//25
            textura_actual++;

        if(ataque == true)
        {
            if(textura_actual == texturas_ataque.end() || textura_actual == texturas_ataque_left.end() || textura_actual == texturas_ataque_up.end() ||
               textura_actual == texturas_ataque_down.end())
            {
                ataque = false;
                if(orientacion == "right" || orientacion == "down" || orientacion == "up")
                    textura_actual = texturas_right.begin();
                else if(orientacion == "left")
                    textura_actual = texturas_left.begin();
            }
        }
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
                textura_actual++;
            }
        }

        if(orientacion=="right")
        {
            if(textura_actual==texturas_right.end())
            {
                textura_actual=texturas_right.begin();
                textura_actual++;
            }
        }

        frame++;
    }

    else
    {
        if(orientacion == "right")
            textura_actual=texturas_right.begin();
        else if(orientacion == "left")
            textura_actual=texturas_left.begin();
        else if(orientacion == "up")
            textura_actual = texturas_right.begin();
        else
            textura_actual = texturas_right.begin();
    }
}
