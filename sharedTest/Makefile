CC=g++
CFLAGS= -fstack-protector -g
OFLAGS= 
WFLAGS= -Werror -Wall
LD_FLAGS=
STDFLAGS = -std=c++17

SRC  = triangle.cpp
OBJS = triangle.o
OBJSEXE = test.o

EXENAME=sharedTest
LDLIBS= -ldl
#VERBOSE= -v

EXENAME=	test
LIB_NAME=	triangle
INC=			-I$(PWD)

.PHONY: all

all: libtriangle.so $(EXENAME)

%.o: %.cpp
	@$(CC) -c $(CFLAGS) $(DFLAGS) $(OFLAGS) $(WFLAGS) $(INC) $(STDFLAGS) $< -o $@
	@echo "[CC] $<"

triangle.o: triangle.cpp
	@$(CC) -c $(CFLAGS) -fPIC $(DFLAGS) $(OFLAGS) $(WFLAGS) $(INC) $(STDFLAGS) $< -o $@
	@echo "[CC] $<"

$(EXENAME): $(OBJSEXE)
	@$(CC) $(VERBOSE) -o $(EXENAME) $(OBJSEXE) $(LDLIBS) -L$(PWD) -l$(LIB_NAME)
	@rm *.o
	@echo "[LD] $<"

libtriangle.so: triangle.o
#$(CC) -shared $< -o $@
	@$(CC) -shared -Wl,-soname,$@.1.0 $(CFLAGS) -o $@ $(OBJS) $(LD_FLAGS)
	@echo "[LD] $<"

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf libtraingle.so $(EXENAME)
