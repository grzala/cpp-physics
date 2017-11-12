#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "Component.h"
#include "Trans.h"

enum RendererType {
    CIRCLE,
};

class Renderer: public Component
{
    public:
        Renderer();
        virtual ~Renderer();

        virtual void render(sf::RenderWindow* app, Trans* trans) = 0;

        RendererType getType() {return type;}

    protected:
        RendererType type;

    private:
};

#endif // RENDERER_H
