CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++2a

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

std_function: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o std_function $(OBJS)

clean:
	rm -rf *.o std_function