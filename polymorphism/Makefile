CC = g++
FLAGS = -Wall
OFLAGS = -O2
STDFLAGS = -std=c++11

#test: $(OBJ) references.h
#	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o references $(SRC)

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

rtPoly: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o rtPoly $(OBJS)

clean:
	rm -rf *.o
