#ifndef COMPONENT_H
#define COMPONENT_H

#include <ComponentManager.h>

class Object;

class Component
{
    public:
        void virtual update(){};

    protected:
        Object* owner;
};

#endif // COMPONENT_H
