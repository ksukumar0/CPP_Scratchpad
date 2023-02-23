CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++2a

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

%.o: %.cpp
	$(CC) -c $(FLAGS) $(OFLAGS) $(STDFLAGS) $< -o $@

all: std_function std_function_cpp_references_example

std_function: std_function.o
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o $@ $@.o

std_function_cpp_references_example: std_function_cpp_references_example.o
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o $@ $@.o

clean:
	rm -rf *.o std_function std_function_cpp_reference
