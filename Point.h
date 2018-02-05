#ifndef POINT_H_
#define POINT_H_

#include "Object.h"

extern const void * Point; /* new(Point, x, y); */

extern const void * PointClass; /* adds draw */

void draw (const void * _self);
void move (void * _self, int dx, int dy);

void initPoint (void);

#endif /* POINT_H_ */
