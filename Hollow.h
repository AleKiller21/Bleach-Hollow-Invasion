#ifndef HOLLOW_H
#define HOLLOW_H
#include "NPC.h"

class Hollow : public NPC
{
    public:
        Hollow(int x, int y,SDL_Renderer* renderer, list<Personaje*>*personajes);
        virtual ~Hollow();
    protected:
    private:
};

#endif // HOLLOW_H
