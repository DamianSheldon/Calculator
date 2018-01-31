/*
 * new_private
 *
 *  Created on: Jan 31, 2018
 *      Author: dongmeiliang
 */

#ifndef NEW_PRIVATE_H_
#define NEW_PRIVATE_H_

struct Class {
	size_t size;
	void * (* ctor) (void * self, va_list * app);
	void * (* dtor) (void * self);
	void * (* clone) (const void * self);
	int (* differ) (const void * self, const void * b);
};

#endif /* NEW_PRIVATE_H_ */
