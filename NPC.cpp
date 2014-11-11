#include "NPC.h"

NPC::NPC(int x, int y,SDL_Renderer* renderer, list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc1/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/down2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";

//    if(x >= 0 && x <= 125)
//    {
//        textura_actual = texturas_right;
//        orientacion = "right";
//    }
//
//    else if(x >= 126 && x <= 250)
}

NPC::NPC()
{

}

NPC::~NPC()
{
    //dtor
}

void NPC::randomize()
{
    int x = rand() % 4;
    //cout << "randomize" << endl;
    if(x == 0)
    {
        textura_actual = texturas_right.begin();
        orientacion = "right";
        rectangulo.x = 0;
        cout << "va derecha" << endl;
    }

    else if(x == 1)
    {
        textura_actual = texturas_left.begin();
        orientacion = "left";
        rectangulo.x = 500;
        //cout << "Fallo" << endl;
    }

    else if(x == 2)
    {
        textura_actual = texturas_up.begin();
        rectangulo.y = 300;
        orientacion = "up";
        cout << "va arriba" << endl;
    }

    else
    {
        textura_actual = texturas_down.begin();
        orientacion = "down";
        rectangulo.x = 0;
        cout << "va abajo" << endl;
    }
}

void NPC::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

    if(orientacion == "right")
    {
        rectangulo.x++;
        if(rectangulo.x>560)
        {
            randomize();
        }
    }

    else if(orientacion == "left")
    {
        rectangulo.x--;
        cout << "Fallo" << endl;
        if(rectangulo.x < 30)
        {
            randomize();
        }
    }

    else if(orientacion == "up")
    {
        rectangulo.y--;
        if(rectangulo.y < 30)
        {
            randomize();
        }
    }

    else if(orientacion == "down")
    {
        rectangulo.y++;
        if(rectangulo.y > 340)
        {
            randomize();
        }
    }

//    for(list<Personaje*>::iterator i = personajes->begin(); i!=personajes->end(); i++)
//    {
//        if(this==(*i))
//            continue;
//        if(colision(this->rectangulo, (*i)->rectangulo))
//            rectangulo=temp;
//    }
}
