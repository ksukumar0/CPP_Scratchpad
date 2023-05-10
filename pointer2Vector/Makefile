CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++2a -g

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

all: pointer2Vector

%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

pointer2Vector: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o pointer2Vector $(OBJS)

clean:
	rm -rf *.o pointer2Vector