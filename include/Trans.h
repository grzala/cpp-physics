#ifndef TRANS_H
#define TRANS_H


#include <SFML/System/Vector2.hpp>

#include "Component.h"

using namespace sf;

class Trans: public Component
{
    public:
        Trans();
        virtual ~Trans();

        void setPos(double x, double y) {pos.x = x; pos.y = y;}
        void setVel(double x, double y) {vel.x = x; vel.y = y;}
        void accel(double x, double y) {vel.x += x; vel.y += y;}

        Vector2f getPosition() {return pos;}
        Vector2f getVelocity() {return vel;}

        void update() override;

    private:
        Vector2f pos;
        Vector2f vel;
};

#endif // TRANS_H
