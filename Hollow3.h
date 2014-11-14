#ifndef HOLLOW3_H
#define HOLLOW3_H
#include "NPC.h"

class Hollow3 : public NPC
{
    public:
        Hollow3(int x, int y,SDL_Renderer* renderer, list<Personaje*>*personajes);
        virtual ~Hollow3();
    protected:
    private:
};

#endif // HOLLOW3_H
