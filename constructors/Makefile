CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++11

#SRC = scope.cpp
#OBJ = scope.o
#
#test: $(OBJ) references.h
#	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o references $(SRC)

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

construct: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o construct $(OBJS)

clean:
	rm -rf *.o
