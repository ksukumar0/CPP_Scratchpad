CC = clang
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC = uniqPtr.cpp
OBJ = uniqPtr.o

uniqPtr: $(OBJ)
	gcc -o uniqPtr $(OBJ) -lstdc++ 

%.o: %.cpp
	$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC
