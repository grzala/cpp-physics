#ifndef ENGINE_H
#define ENGINE_H

#include <ctime>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Object.h"



class Engine
{
    public:
        Engine();
        virtual ~Engine();
        virtual void init();

        static double MS_PER_UPDATE;

    protected:
        void init(int width, int height, const char* s);
        void gameLoop();

        virtual void update();
        virtual void handleInput();
        virtual void render();

        sf::RenderWindow* app;

        std::vector<Object*> objects;
    private:
        bool running;
};

#endif // ENGINE_H
