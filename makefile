SHELL = /bin/sh
#### Start of system configuration section. ####
srcdir = .
# If you use gcc, you should either run the
# fixincludes script that comes with it or else use
# gcc with the -traditional option.  Otherwise ioctl
# calls will be compiled incorrectly on some systems.
CC = gcc -O
YACC = bison -y
INSTALL = /usr/local/bin/install -c
INSTALLDATA = /usr/local/bin/install -c -m 644
# Things you might add to DEFS:

DEFS =  -DSIGTYPE=int -DDIRENT -DSTRSTR_MISSING \
        -DVPRINTF_MISSING -DBSD42
# Set this to rtapelib.o unless you defined NO_REMOTE,
# in which case make it empty.
LIBS =
DEF_AR_FILE = /dev/rmt8
DEFBLOCKING = 20
CDEBUG = -g
CFLAGS = $(CDEBUG) -I. -I$(srcdir) $(DEFS) \
        -DDEF_AR_FILE=\"$(DEF_AR_FILE)\" \
        -DDEFBLOCKING=$(DEFBLOCKING)
LDFLAGS = -g
prefix = /usr/local
# Prefix for each installed program,
# normally empty or ‘g’.
binprefix =
# The directory to install tar in.
bindir = $(prefix)/bin
# The directory to install the info files in.
infodir = $(prefix)/info
#### End of system configuration section. ####

SRCS_OBJECT_SUPPORT = new.c
SRCS_STRING = String.c

SRCS_STRING_TESTS = $(SRCS_OBJECT_SUPPORT) $(SRCS_STRING) test_string.c

SRCS_C = $(SRCS_STRING) $(SRCS_OBJECT_SUPPORT)

.PHONY: all
all: $(SRCS_C)
	$(CC) $(LDFLAGS) -o $@ $(SRCS_C) $(LIBS)

test_string: $(SRCS_STRING_TESTS)
	$(CC) $(LDFLAGS) -o $@ $(SRCS_STRING_TESTS) $(LIBS)

.PHONY: clean
clean:
