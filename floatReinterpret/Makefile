CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

floatReinterpret: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o floatReinterpret $(OBJS)

clean:
	rm -rf *.o
