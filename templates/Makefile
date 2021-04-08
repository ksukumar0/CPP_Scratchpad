CC = clang
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC = template.cpp
OBJ = template.o

template: $(OBJ) template.h
	gcc -o template $(OBJ) -lstdc++ 

%.o: %.cpp
	$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC
