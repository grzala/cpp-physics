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

struct CollisionPoint {
    bool point1col = false;
    bool point2col = false;
    Vector2f point1;
    Vector2f point2;
    Vector2f normal1;
    Vector2f normal2;
};

Vector2f normalizeVector(Vector2f norm) {
    return norm / (float)sqrt((norm.x*norm.x) + (norm.y*norm.y));
}

void CircleWallCollision(Circle& cir, Wall& wall, CollisionPoint& colPoint)
{
    Vector2f lineA = wall.line[0].position; Vector2f lineB = wall.line[1].position;
    Vector2f w1 = lineA - cir.pos;
    float ww1 = (w1.x * w1.x) + (w1.y * w1.y);
    Vector2f w2 = lineB - cir.pos;
    float ww2 = (w2.x * w2.x) + (w2.y * w2.y);

    float rr = cir.radius * cir.radius;

    Vector2f wallvector = (lineB - lineA);
    Vector2f wallnormal = wallvector;
    wallnormal = Vector2f(-wallnormal.y, wallnormal.x);
    wallnormal = normalizeVector(wallnormal)*80.f;
    Vector2f cTow1 = cir.pos - lineA;
    Vector2f cTow2 = cir.pos - lineB;
    float dot = (wallnormal.x * cTow1.x) + (wallnormal.y * cTow1.y);
    if (dot < 0) {
        wallnormal = Vector2f(-wallnormal.x, -wallnormal.y);
    }

    if (ww1 < rr) {
        colPoint.point1col = true;
        colPoint.point1 = lineA;

        float dot2 = (cTow1.x * wallvector.x) + (cTow1.y * wallvector.y);
        if (dot2 > 0)
            colPoint.normal1 = wallnormal;
        else
            colPoint.normal1 = normalizeVector(cir.pos - lineA)*80.f;

        return;
    } else if (ww2 < rr) {
        colPoint.point1col = true;
        colPoint.point1 = lineB;

        float dot2 = (cTow2.x * wallvector.x) + (cTow2.y * wallvector.y);
        if (dot2 < 0)
            colPoint.normal1 = wallnormal;
        else
            colPoint.normal1 = normalizeVector(cir.pos - lineB)*80.f;
        return;
    }

    Vector2f v = lineB-lineA;
    float a = (v.x * v.x) + (v.y * v.y);
    float b = (v.x * w1.x) + (v.y * w1.y);
    float c = ww1 - rr;

    float root = (b*b)-(a*c);

    if (root < 0) return;

    float t1 = (-b-sqrt(root))/a;
    if (t1 > 0.0 && t1 < 1.0) {
        colPoint.point1col = true;
        colPoint.point1 = lineA + (lineB - lineA)*t1;
        colPoint.normal1 = wallnormal;
    }

    float t2 = (-b+sqrt(root))/a;
    if (t2 > 0.0 && t2 < 1.0) {
        colPoint.point2col = true;
        colPoint.point2 = lineA + (lineB - lineA)*t2;
        colPoint.normal2 = wallnormal;
    }


}

std::vector<Vector2f> toDraw;
std::vector<std::pair<Vector2f, Vector2f>> toDrawLines;

class CircleToWall: public Engine {
    public:

    void init() {
        circle.radius = 25.0;
        circle.pos = sf::Vector2f(10.0, 10.0);
        circle.shape = sf::CircleShape(circle.radius);
        circle.shape.setFillColor(sf::Color(150, 50, 250));
        circle.shape.setOrigin(Vector2f(circle.radius, circle.radius));
        //circle.vel = sf::Vector2f(0.05, 0.05);

        wall.line[0] = sf::Vertex(sf::Vector2f(400, 30));
        wall.line[1] = sf::Vertex(sf::Vector2f(30, 400));

        Engine::init();
    }

    void update() {
        //circle.pos += circle.vel;
        circle.pos = Vector2f(sf::Mouse::getPosition(*app));
        //circle.pos -= Vector2f(circle.radius, circle.radius);

        CollisionPoint colPoint;
        CircleWallCollision(circle, wall, colPoint);

        if (colPoint.point1col) {
            toDraw.push_back(colPoint.point1);
            toDrawLines.push_back(std::pair<Vector2f, Vector2f>(colPoint.point1, colPoint.point1+colPoint.normal1));
        }
        if (colPoint.point2col) {
            toDraw.push_back(colPoint.point2);
            toDrawLines.push_back(std::pair<Vector2f, Vector2f>(colPoint.point2, colPoint.point2+colPoint.normal2));
        }
    }

    void draw(sf::RenderWindow* app) {
        circle.shape.setPosition(circle.pos);
        app->draw(circle.shape);
        app->draw(wall.line, 3, sf::Lines);

        for (unsigned int i = 0; i < toDraw.size(); i++) {
            sf::CircleShape p(5.f);
            p.setOrigin(5.f, 5.f);
            p.setPosition(toDraw[i]);
            p.setFillColor(sf::Color(255, 0, 0));
            app->draw(p);
        }
        toDraw.clear();

        for (unsigned int i = 0; i < toDrawLines.size(); i++) {
            sf::Vertex line[2];
            line[0] = toDrawLines[i].first;
            line[1] = toDrawLines[i].second;
            app->draw(line, 2, sf::Lines);
        }
        toDrawLines.clear();


    }

};

int main()
{
    std::cout << "start program" << std::endl;
    CircleToWall e;
    std::cout << "start engine" << std::endl;
    e.init();
}
