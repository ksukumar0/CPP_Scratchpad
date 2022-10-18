CC = g++
WFLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++17
LDFLAGS = -fsanitize=address

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

SCRATCH_OBJS = scratch.o random.o
TEST_OBJS = test.o
SORT_OBJS = sort.o

scratch: $(SCRATCH_OBJS)
	$(CC) $(LDFLAGS) -o scratch $(SCRATCH_OBJS)

test: $(TEST_OBJS)
	$(CC) $(LDFLAGS) -o test $(TEST_OBJS)

sort: $(SORT_OBJS)
	$(CC) $(LDFLAGS) -o sort $(SORT_OBJS)

%.o: %.cpp
	$(CC) -c -g $(WFLAGS) $(LDFLAGS) $(OFLAGS) $(STDFLAGS) $< -o $@

clean:
	rm -rf *.o
