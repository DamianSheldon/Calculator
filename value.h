#ifndef VALUE_H_
#define VALUE_H_

const void * Add;

void * new(const void * type, ...);
void process(const void * tree);
void delete(void * tree);

#endif /* VALUE_H_ */
