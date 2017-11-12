#ifndef CIRCLERENDERER_H
#define CIRCLERENDERER_H

#include "Renderer.h"


class CircleRenderer : public Renderer
{
    public:
        CircleRenderer();
        virtual ~CircleRenderer();


        void render(sf::RenderWindow* app, Trans* trans) override;
        void setRadius(double r) {shape->setRadius(r);}

    private:
        sf::CircleShape* shape;
};

#endif // CIRCLERENDERER_H
