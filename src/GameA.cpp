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
    CircleRenderer* rendererA = new CircleRenderer();
    rendererA->setRadius(20.0);
    Trans* trA = new Trans();
    trA->setPos(20.0, 20.0);
    trA->accel(0.05, 0.08);
    Collider* colliderA = new Collider();
    objectA->setComponents(rendererA, colliderA, trA);


    Object* objectB = new Object();
    RectangleRenderer* rendererB = new RectangleRenderer();

    Trans* trB = new Trans();
    trB->setPos(20.0, 20.0);
    trB->accel(0.05, 0.08);
    Collider* colliderB = new Collider();
    objectB->setComponents(rendererB, colliderB, trB);

    objects.push_back(objectA);
    objects.push_back(objectB);

    std::cout << "GameA initialzied" << std::endl;
    Engine::init();
}
