#ifndef OBJECT_PRIVATE_H_
#define OBJECT_PRIVATE_H_

#include <stddef.h>
#include <stdarg.h>

struct Class;

struct Object {
    const struct Class * class; /* object's description */
};

struct Class {
    const struct Object _; /* class' description */
    const char * name; /* class' name */
    const struct Class * super; /* class' super class */
    size_t size;
    void * (* ctor) (void * self, va_list * app);
    void * (* dtor) (void * self);
    int (* differ) (const void * self, const void * b);
    int (* puto) (const void * self, FILE * fp);
};

const void * classOf(const void * _self);
size_t sizeOf(const void * _self);

const void * super(const void * _self);

void * super_ctor (const void * _class, void * _self, va_list * app);
void * super_dtor (const void * _class, void * _self);

#endif /* OBJECT_PRIVATE_H_ */
