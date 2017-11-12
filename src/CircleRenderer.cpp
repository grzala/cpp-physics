#include "CircleRenderer.h"

CircleRenderer::CircleRenderer()
{
    type = RendererType::CIRCLE;

    shape = new sf::CircleShape(50);

    shape->setFillColor(sf::Color(150, 50, 250));
}

CircleRenderer::~CircleRenderer()
{
    delete shape;
}

void CircleRenderer::render(sf::RenderWindow* app, Trans* trans) {

    shape->setPosition(trans->getPosition());

    app->draw(*shape);
}
