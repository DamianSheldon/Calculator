/*
 * new
 *
 *  Created on: Jan 30, 2018
 *      Author: dongmeiliang
 */

#ifndef NEW_H_
#define NEW_H_

#include <stddef.h>

void * new (const void * _class, ...);
void delete (void * self);

void * clone (const void * self);
int differ (const void * self, const void * b);
size_t sizeOf (const void * self);

#endif /* NEW_H_ */
