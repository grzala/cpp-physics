#include "Engine.h"

#include <iostream>
#include <SFML/System/Vector2.hpp>

struct Circle {
    sf::Vector2f pos;
    sf::CircleShape shape;
    sf::Vector2f vel;
    double radius;
};

struct Wall {
    sf::Vertex line[2];
};

Circle circle;
Wall wall;

bool CircleWallCollision(Circle& c, Wall& w)
{

    return false;
}

class CircleToWall: public Engine {
    public:

    void init() {
        circle.radius = 45.0;
        circle.pos = sf::Vector2f(10.0, 10.0);
        circle.shape = sf::CircleShape(circle.radius);
        circle.shape.setFillColor(sf::Color(150, 50, 250));
        circle.vel = sf::Vector2f(0.05, 0.05);

        wall.line[0] = sf::Vertex(sf::Vector2f(400, 30));
        wall.line[1] = sf::Vertex(sf::Vector2f(30, 400));

        Engine::init();
    }

    void update() {
        circle.pos += circle.vel;

        bool colliding = CircleWallCollision(circle, wall);

        std::cout << "Collision: " << colliding << std::endl;
    }

    void draw(sf::RenderWindow* app) {
        circle.shape.setPosition(circle.pos);
        app->draw(circle.shape);


        app->draw(wall.line, 2, sf::Lines);

    }

};

int main()
{
    std::cout << "start program" << std::endl;
    CircleToWall e;
    std::cout << "start engine" << std::endl;
    e.init();
}
