#include <stdio.h>

#include "Point.h"
#include "Circle.h"

void usage(void);

int main (int argc, char ** argv)
{
    if (argc < 2) {
        usage();
        return 0;
    }

    initPoint();
    initCircle();

    void *p;

    while (* ++ argv) {
        switch (** argv) {
            case 'p':
                p = new(Point, 1, 2);
                // printf("new Point 1, 2 addr at %p\n", p);
                break;
            
            case 'c':
                p = new(Circle, 1, 2, 3);
                break;
            default:
                usage();
                return 0;
        }

        draw(p);
        move(p, 10, 20);
        draw(p);
        delete(p);
    }

    return 0;
}

void usage(void)
{
    puts("./test_point [p | c]");
}
