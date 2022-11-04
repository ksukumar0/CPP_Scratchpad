CC = g++
FLAGS = -Wall -Werror
OFLAGS = 
STDFLAGS = -std=c++14

SRC = $(wildcard *.cpp)
OBJS = $(subst .cpp,.o,$(SRC))

uniqPtr: $(OBJS)
	$(CC) -o uniqPtr $(OBJS) -lstdc++

%.o: %.cpp
	$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC

clean:
	rm -rf *.o
	rm -rf uniqPtr
