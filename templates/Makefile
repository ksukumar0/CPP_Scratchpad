CC = gcc
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++17

SRC = template.cpp
OBJ = template.o

template: $(OBJ) template.h
	gcc -o template $(OBJ) -lstdc++ 

%.o: %.cpp
	$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC

clean:
	rm -rf *.o
	rm template
