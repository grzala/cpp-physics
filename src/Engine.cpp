#include "Engine.h"

double Engine::MS_PER_UPDATE = 60;

int test = 0;

Engine::Engine()
{

}

void Engine::init()
{
    init(640, 480, "Game Engine");
}

void Engine::init(int width, int height, const char* c)
{
    app = new sf::RenderWindow(sf::VideoMode(width, height), c);

    running = true;
    std::cout << "Starting Game Loop" << std::endl;
    gameLoop();
}

void Engine::gameLoop()
{
    std::cout << "init game loop" << std::endl;
    double previous = clock();
    double current;
    double lag = 0.d;
    std::cout << "start game loop" << std::endl;
    while(running)
    {
        current = clock();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        handleInput();

        while (lag > MS_PER_UPDATE)
        {
            update();
            lag -= MS_PER_UPDATE;
        }
        render();
    }
    app->close();
}
void Engine::handleInput()
{
    // Process events
    sf::Event event;
    while (app->pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed)
            running = false;
    }
}

void Engine::update()
{
    for (auto object : objects)
        object->update();
}

void Engine::render()
{
    // Clear screen
    app->clear();

    for (auto object : objects) {
        object->render(app);
    }

    // Update the window
    app->display();
}


Engine::~Engine()
{
    delete app;
}
