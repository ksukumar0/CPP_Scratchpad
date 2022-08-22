CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC = virtualDest.cpp
OBJ = virtualDest.o

virtualDest: $(OBJ)
	gcc -o virtualDest $(OBJ) -lstdc++ 

%.o: %.cpp
	$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC
