#include "GameA.h"

GameA::GameA()
{
    //ctor
}

GameA::~GameA()
{
    //dtor
}

void GameA::init()
{
    Object* objectA = new Object();

    objects.push_back(objectA);

    std::cout << "GameA initialzied" << std::endl;
    Engine::init();
}
