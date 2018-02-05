SHELL = /bin/sh
#### Start of system configuration section. ####
srcdir = .
# If you use gcc, you should either run the
# fixincludes script that comes with it or else use
# gcc with the -traditional option.  Otherwise ioctl
# calls will be compiled incorrectly on some systems.
CC = gcc 
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

#CFLAGS = -I. -I$(srcdir) $(DEFS) \
        -DDEF_AR_FILE=\"$(DEF_AR_FILE)\" \
        -DDEFBLOCKING=$(DEFBLOCKING)

CFLAGS = -I. -I$(srcdir) \
		 -Wno-nonportable-include-path \
		 -Wno-implicit-function-declaration

LDFLAGS = 
BUILD_MODE = run

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
	LDFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

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

SRCS_POINT_TESTS = Object.c Point.c test_point.c

SRCS_C = $(SRCS_STRING) $(SRCS_OBJECT_SUPPORT)

.PHONY: all
all: $(SRCS_C)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SRCS_C) $(LIBS)

test_string: $(SRCS_STRING_TESTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.app $(SRCS_STRING_TESTS) $(LIBS)

test_point: $(SRCS_POINT_TESTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@.app $(SRCS_POINT_TESTS) $(LIBS)

.PHONY: clean
clean: clean_test_string

clean_test_string:
	rm -rf test_string.app test_string.dSYM

clean_test_point:
	rm -rf test_point.app test_point.dSYM
