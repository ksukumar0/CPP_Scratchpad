CC = g++
FLAGS = -Wall -Werror
OFLAGS = -O2
STDFLAGS = -std=c++14

#SRC  = $(wildcard *.cpp)
#OBJS = $(subst .cpp,.o,$(SRC))

SRC=functor.cpp
OBJ=functor.o
EXENAME=functor

$(EXENAME): $(OBJ)
	$(CC) -o $(EXENAME) $(OBJ)

%.o: %.cpp
	$(CC) -c $(OFLAGS) $(FLAGS) $(STDFLAGS) $< -o $@ -fPIC

clean:
	rm -rf *.o
	rm -rf $(EXENAME)
