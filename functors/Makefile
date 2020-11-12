CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

scratch: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o functors $(OBJS)

clean:
	rm -rf *.o
