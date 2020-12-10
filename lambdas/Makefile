CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

%.o: %.cpp
	@$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@
	@echo "CC $<"

lambdas: $(OBJS)
	@$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o lambdas $(OBJS)
	@echo "CC $<"

clean:
	rm -rf *.o
