#ifndef HOLLOW2_H
#define HOLLOW2_H
#include "NPC.h"

class Hollow2 : public NPC
{
    public:
        Hollow2(int x, int y,SDL_Renderer* renderer, list<Personaje*>*personajes);
        virtual ~Hollow2();
    protected:
    private:
};

#endif // HOLLOW2_H
