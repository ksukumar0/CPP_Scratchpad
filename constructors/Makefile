CC = g++
FLAGS = -Wall -Wreorder
OFLAGS = -O2
STDFLAGS = -std=c++11

#test: $(OBJ) references.h
#	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o references $(SRC)

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))
CONSOBJS=construct.o
DESTOBJS=destructorOrder.o
DESTINHERTOBJS=destOrderInhtce.o
CONSORDEROBJS=constructOrder.o

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

construct: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o construct $(CONSOBJS)

destruct: $(DESTOBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o destruct $(DESTOBJS)

constructOrder: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o constructOrder $(CONSORDEROBJS)

destructInher: $(DESTINHERTOBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o destinhert $(DESTINHERTOBJS)

clean:
	rm -rf *.o
