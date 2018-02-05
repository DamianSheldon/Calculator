#include "Point.h"

int main (int argc, char ** argv)
{
    initPoint();

    void *p;

    while (* ++ argv) {
        switch (** argv) {
            case 'p':
                p = new(Point, 1, 2);
                // printf("new Point 1, 2 addr at %p\n", p);
                break;

            default:
                continue;
        }

        draw(p);
        move(p, 10, 20);
        draw(p);
        delete(p);
    }

    return 0;
}
