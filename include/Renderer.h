#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "Component.h"
#include "Trans.h"

class Trans;

class Renderer: public Component
{
    public:
        Renderer();
        virtual ~Renderer();

        void render(sf::RenderWindow* app, Trans* trans);
    protected:
    private:
};

#endif // RENDERER_H
