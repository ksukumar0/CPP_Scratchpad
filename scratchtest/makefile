CXX=g++
CFLAGS = -fstack-protector-strong -fPIC
OFLAGS = #-O2
#STDFLAGS = -std=c++14

DFLAGS = -DQT_NO_VERSION_TAGGING

QTDIR = /usr/include/qt
INCPATH = -I. -I$(QTDIR)/QtGui -I$(QTDIR)/QtCore -I$(QTDIR)

LIBS =  -lQt5Core -lpthread
#LFLAGS = -Wl,-rpath,$(QTDIR)/lib

ifdef WFLAGS
	${WFLAGS}
	WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .cpp,.o,$(SRC))

TEST_OBJS = test.o

test: $(TEST_OBJS)
	$(CXX) -o test $(LFLAGS) $(LIBS) $(TEST_OBJS)

%.o: %.cpp
	$(CXX) -c $< $(CFLAGS) $(STDFLAGS) $(OFLAGS) $(DFLAGS) $(WFLAGS) $(INCPATH) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
