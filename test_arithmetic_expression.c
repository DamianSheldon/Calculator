#include <setjmp.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>

#include "parse.h" /* defines NUMBER */
#include "value.h"

static enum tokens token; /* current input symbol */

static jmp_buf onError;

static double number; /* if NUMBER: numberical value */

int main (int argc, char ** argv)
{
    volatile int errors = 0;
    char buf [BUFSIZ];

    if (setjmp(onError)) {
        ++ errors;
    }

    while (gets(buf)) {
        if (scan(buf)) {
            void * e = sum();

            if (token) {
                error("trash after sum");
            }

            process(e);

            delete(e);
        }
    }
    
    return errors > 0;
}

void error (const char * fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap), putc('\n', stderr);
    va_end(ap);

    longjmp(onError, 1);
}

/* return token = next input symbol */
static enum tokens scan (const char * buf)
{
    static const char * bp;
    
    if (buf) {
        bp = buf;
    }

    while (isspace(* bp)) {
        ++ bp;
    }

    if (isdigit(* bp) || * bp == '.') {
        errno = 0;
        token = NUMBER, number = strtod(bp, (char **)& bp);
        if (errno == ERANGE) {
            error("bad value: %s", strerror(errno));
        }
        else {
            token = * bp ? * bp ++ : 0;
        }

        return token;
    }
}

void sum (void)
{
    void * result = product();
    const void * type;

    for (;;) {
        switch (token) {
            case '+':
                type = Add;
                break;
            case '-':
                type = Sub;
                break;
            default:
                return result;
        }

        scan(0);
        result = new(type, result, product());
    }
}

static void * factor (void)
{
    void * result;
    
    switch (token) {
        case '+':
            scan(0);
            return factor();
        case '-':
            scan(0);
            return new(Minus, factor());
        default:
            error("bad factor: '%c' 0x%x", token, token);
        case NUMBER:
            result = new(Value, number);
            break;
        case '(':
            scan(0);
            result = sum();
            if (token != ')') {
                error("expecting )");
            }
    }
    scan(0);
    return result;
}
