CXX=g++
CFLAGS = -fstack-protector-strong -fPIC -fsanitize=address
OFLAGS = -O2
STDFLAGS = -std=c++14

DFLAGS = -DQT_NO_VERSION_TAGGING

QTDIR = /usr/include/qt
INCPATH = -I. -I$(QTDIR)/QtGui -I$(QTDIR)/QtCore -I$(QTDIR)

LDFLAGS =  -lQt5Core -lpthread
LDFLAGS += -fsanitize=address

ifndef WFLAGS
#WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .cpp,.o,$(SRC))

TEST_OBJS = test.o
FILELENGTH_OBJS = fileLength.o

test: $(TEST_OBJS)
	$(CXX) -o test $(LDFLAGS) $(LIBS) $(TEST_OBJS)

fileLen: $(FILELENGTH_OBJS)
	$(CXX) -o fileLen $(LDFLAGS) $(LIBS) $(FILELENGTH_OBJS)

%.o: %.cpp
	$(CXX) -c -g $< $(CFLAGS) $(STDFLAGS) $(OFLAGS) $(DFLAGS) $(WFLAGS) $(INCPATH) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
