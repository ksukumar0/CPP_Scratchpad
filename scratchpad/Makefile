CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

SCRATCH_OBJS = scratch.o random.o
TEST_OBJS = test.o

scratch: $(SCRATCH_OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o scratch $(SCRATCH_OBJS)

test: $(TEST_OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o test $(TEST_OBJS)
	
%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

clean:
	rm -rf *.o
