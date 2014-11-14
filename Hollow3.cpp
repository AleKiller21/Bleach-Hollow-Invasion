#include "Hollow3.h"

Hollow3::Hollow3(int x, int y,SDL_Renderer* renderer, list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/Bleach/NPCs/Hollow3/right1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_right.push_back(textura);
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/Bleach/NPCs/Hollow3/right2.png"));

    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/NPCs/Hollow3/left1.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/Bleach/NPCs/Hollow3/left2.png"));

    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/NPCs/Hollow3/up1.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/Bleach/NPCs/Hollow3/up2.png"));

    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/NPCs/Hollow3/down1.png"));
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/Bleach/NPCs/Hollow3/down2.png"));

    if(y <= 110)
    {
        textura_actual=texturas_down.begin();
        orientacion="down";
        //cout << "y: " << y << endl;
    }

    else if(y >= 487)
    {
        textura_actual=texturas_up.begin();
        orientacion="up";
        //cout << "y: " << y << endl;
    }

    else if (x <= 457)
    {
        textura_actual = texturas_right.begin();
        orientacion = "right";
        //cout << "x: " << x << endl;
    }

    else if(x > 457)
    {
        textura_actual = texturas_left.begin();
        orientacion = "left";
        //cout << "x: " << x << endl;
    }
    id = "Hollow3";
}

Hollow3::~Hollow3()
{
    //dtor
}
