CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC  = main.cpp
OBJS = main.o

EXENAME=sharedObj


.PHONY: all

all: libtriangle.so $(EXENAME)

$(EXENAME): $(OBJS)
	$(CC) -o $(EXENAME) $(OBJS) -Wl,-rpath=$(PWD) -L$(PWD) -ltriangle

%.o: %.cpp
	@$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC

libtriangle.so: triangle.o
	$(CC) -shared $< -o $@ -fPIC

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf $(EXENAME)
	rm -rf libtraingle.so
