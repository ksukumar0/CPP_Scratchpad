CC = g++
FLAGS = -Wall
OFLAGS = -O2
STDFLAGS = -std=c++11

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))
RTPOLY_SRC=virtInhert.cpp staticBase.cpp
RTPOLY_OBJS=$(subst .cpp,.o,$(RTPOLY_SRC))
%.o: %.cpp
	$(CC) -c $(FLAGS) $(STDFLAGS) $< -o $@

rtPoly: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(STDFLAGS) -o rtPoly $(RTPOLY_OBJS)

clean:
	rm -rf *.o
