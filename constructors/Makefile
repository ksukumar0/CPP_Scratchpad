CC = g++
FLAGS = -Wall
OFLAGS = -O2
STDFLAGS = -std=c++11

#test: $(OBJ) references.h
#	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o references $(SRC)

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))
DESTOBJS=destructorOrder.cpp
DESTINHERTOBJS=destOrderInhtce.cpp

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

construct: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o construct $(OBJS)

destruct: $(DESTOBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o destruct $(DESTOBJS)

destructInher: $(DESTINHERTOBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o destinhert $(DESTINHERTOBJS)

clean:
	rm -rf *.o
