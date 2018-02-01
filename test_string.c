#include <stdio.h>

#include "String.h"
#include "new.h"

int main (int arc, char ** argv) {
    
    void * a = new(String, "a"), * aa = clone(a);
    void * b = new(String, "b");

    printf("sizeOf(a) == %zu\n", sizeOf(a));

    if (differ(a, b)) {
        puts("a b ok");
    }

    if (differ(a, aa)) {
        puts("a aa differ?");
    }

    if (a == aa) {
        puts("a aa clone?");
    }

    delete(a);
    delete(aa);
    delete(b);

    return 0;
}
