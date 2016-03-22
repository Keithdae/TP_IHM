#include "shape.h"

shape::shape()
{
    type = 1;
}


void shape::clearPoints()
{
    points.clear();
    start.setX(0);
    start.setY(0);
    end.setX(0);
    end.setY(0);
}
