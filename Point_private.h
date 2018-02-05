#ifndef POINT_PRIVATE_H_
#define POINT_PRIVATE_H_

#include "Object_private.h"

struct Point {
    const struct Object _; /* Point : Object */
    int x, y; /* coordinates */
};

#define x(p) (((const struct Point *)(p)) -> x)
#define y(p) (((const struct Point *)(p)) -> y)

void super_draw (const void * class, const void * self);

struct PointClass {
    const struct Class _; /* PointClass : Class */
    void (* draw) (const void * self);
};

#endif /* POINT_PRIVATE_H_ */
