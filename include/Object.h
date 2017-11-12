#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

#include <vector>

#include <iostream>

#include "Component.h"
#include "CircleRenderer.h"
#include "Renderer.h"
#include "Trans.h"
#include "Collider.h"

class Object
{
    public:
        Object();
        virtual ~Object();

        std::vector<Component*> getComponents() {return components;}

        void update();
        void render(sf::RenderWindow* app);

        void setComponents(Renderer* r, Collider* c, Trans* tr);

        void setPos(double x, double y) {tr->setPos(x, y);}
        void accelerate(double x, double y) {tr->accel(x, y);}


    private:
        std::vector<Component*> components;
        Renderer* renderer;
        Collider* collider;
        Trans* tr;
};

#endif // OBJECT_H
