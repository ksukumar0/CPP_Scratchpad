CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC = vectorDest.cpp
OBJ = vectorDest.o

vectorDest: $(OBJ)
	gcc -o vectorDest $(OBJ) -lstdc++ 

%.o: %.cpp
	$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC

clean:
	rm -rf *.o
	rm -rf vectorDest
