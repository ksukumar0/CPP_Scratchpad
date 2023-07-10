CC = g++
CFLAGS = -fstack-protector-strong -fsanitize=address
WFLAGS= -Werror -Wall
OFLAGS = -O2
STDFLAGS = -std=c++2a

INCDIR = /opt/boost/include
INCPATH = -I$(INCDIR)

LDFLAGS = -fsanitize=address

SRC = $(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRC))

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(STDFLAGS) $(WFLAGS) $(OFLAGS) $(INCPATH) $< -o $@

boostMultiprecision: $(OBJS)
	$(CC) $(FLAGS) $(OFLAGS) $(LDFLAGS) $(STDFLAGS) -o boostMultiprecision $(OBJS)

clean:
	rm -rf *.o boostMultiprecision
