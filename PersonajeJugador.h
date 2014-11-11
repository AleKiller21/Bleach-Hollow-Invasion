#ifndef PERSONAJEJUGADOR_H
#define PERSONAJEJUGADOR_H
#include "Personaje.h"
#include <iostream>

class PersonajeJugador : public Personaje
{
    public:
        bool moviendo = false;
        bool ataque = false;
        PersonajeJugador(int x, int y, SDL_Renderer* renderer, list<Personaje*>*personajes);
        void logic(Uint8* teclas_presionadas);
        void render(SDL_Renderer* renderer);
        virtual ~PersonajeJugador();
    protected:
    private:
};

#endif // PERSONAJEJUGADOR_H
