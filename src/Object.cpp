#include "Object.h"

Object::Object()
{
    renderer = new Renderer();
    collider = new Collider();
    tr = new Trans();

    tr->setPos(20, 20);
    tr->setVel(0.05, 0.05);

    components.push_back(renderer);
    components.push_back(collider);
    components.push_back(tr);
}

Object::~Object()
{
    delete renderer;
    delete collider;
    delete tr;
}

void Object::update()
{
    for (auto component : components)
        component->update();
}

void Object::render(sf::RenderWindow* app)
{

    renderer->render(app, tr);
}
