/*
 * Set
 *
 *  Created on: Jan 30, 2018
 *      Author: dongmeiliang
 */

#ifndef SET_H_
#define SET_H_

extern const void * Set;
void * add (void * set, const void * element);
void * find (const void * set, const void * element); void * drop (void * set, const void * element);
int contains (const void * set, const void * element);

#endif /* SET_H_ */
