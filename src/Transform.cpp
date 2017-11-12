#include "Trans.h"

Trans::Trans()
{
    //ctor
}

Trans::~Trans()
{
    //dtor
}

void Trans::update()
{
    pos += vel;
}
