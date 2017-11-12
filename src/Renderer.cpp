#include "Renderer.h"

Renderer::Renderer()
{
    //ctor
}

Renderer::~Renderer()
{
    //dtor
}

void Renderer::render(sf::RenderWindow* app, Trans* trans) {
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(150, 50, 250));

    shape.setPosition(trans->getPosition());

    app->draw(shape);
}
