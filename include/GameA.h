#ifndef GAMEA_H
#define GAMEA_H

#include "Engine.h"


class GameA : public Engine
{
    public:
        GameA();
        virtual ~GameA();

        void init() override;
};

#endif // GAMEA_H
