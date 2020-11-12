CC = g++
FLAGS = -Wall
OFLAGS = -O2
STDFLAGS = -std=c++11

#test: $(OBJ) references.h
#	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o references $(SRC)

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

DESTOBJS=destructorOrder.cpp

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

construct: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o construct $(OBJS)

destruct: $(DESTOBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o destruct $(DESTOBJS)

clean:
	rm -rf *.o
