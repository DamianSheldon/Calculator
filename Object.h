/*
 * Object.h
 *
 *  Created on: Jan 30, 2018
 *      Author: dongmeiliang
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdio.h>

extern const void * Object; /* new(Object); */

extern const void * Class; /* new(Class, "name", super, size, sel, meth, ...0); */

void * new (const void * class, ...);
void delete (void * self);

void * ctor (void * self, va_list * app);
void * dtor (void * _self);
int differ (const void * self, const void * b);
int puto (const void * self, FILE * fp);


#endif /* OBJECT_H_ */
