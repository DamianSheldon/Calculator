#include <stdarg.h>

#include "Point.h"
#include "Point_private.h"
#include "Circle.h"
#include "Circle_private.h"

const void * Circle;

static void Circle_draw (const void * _self)
{
    const struct Circle * self = _self;

    printf("circle at %d,%d rad %d\n", self -> _.x, self -> _.y, self -> rad);
}

static void * Circle_ctor (void * _self, va_list * app)
{
    struct Circle * self = super_ctor(Circle, _self, app);

    self -> rad = va_arg(* app, int);

    return self;
}

void initCircle (void)
{
    if (! Circle) {
        initPoint();

        Circle = new(PointClass, "Circle", Point, sizeof(struct Circle), ctor, Circle_ctor, draw, Circle_draw, 0);
    }
}
