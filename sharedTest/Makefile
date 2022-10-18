CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC  = triangle.cpp
OBJS = triangle.o

EXENAME=sharedObj


.PHONY: all

all: libtriangle.so

%.o: %.cpp
	$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC

libtriangle.so: triangle.o
	$(CC) -shared $< -o $@

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf libtraingle.so
