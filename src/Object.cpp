#include "Object.h"

Object::Object()
{
    renderer = new CircleRenderer();
    collider = new Collider();
    tr = new Trans();

    components.push_back(renderer);
    components.push_back(collider);
    components.push_back(tr);
}

void Object::setComponents(Renderer* r, Collider* c, Trans* t)
{
    renderer = r;
    collider = c;
    tr = t;

    components.clear();
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
