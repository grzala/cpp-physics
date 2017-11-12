#ifndef RECTANGLERENDERER_H
#define RECTANGLERENDERER_H

#include "Renderer.h"


class RectangleRenderer : public Renderer
{
    public:
        RectangleRenderer();
        virtual ~RectangleRenderer();


        void render(sf::RenderWindow* app, Trans* trans) override;
    protected:
    private:
};

#endif // RECTANGLERENDERER_H
