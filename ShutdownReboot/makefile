CXX=clang
CFLAGS = -fstack-protector-strong -fPIC -fsanitize=address
OFLAGS = -O2
STDFLAGS = -std=c++14

DFLAGS = -DQT_NO_VERSION_TAGGING

QT_LIB_INSTALL_PATH = /usr/include/arm-linux-gnueabihf/qt5
QTDIRINC = /usr/include/arm-linux-gnueabihf/qt5
INCPATH = -I. -I$(QTDIRINC) -I$(QTDIRINC)/QtCore

LDFLAGS += -fsanitize=address -lQt5Core

LIBS += -L${QT_LIB_INSTALL_PATH}

ifndef WFLAGS
#WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .cpp,.o,$(SRC))

TEST_OBJS = test.o
FILELENGTH_OBJS = fileLength.o

test: $(TEST_OBJS)
ifeq ($(CXX),g++)
	$(CXX) -o test $(LDFLAGS) $(TEST_OBJS)
else
	$(CXX) -o test $(LDFLAGS) -lstdc++ $(TEST_OBJS)
endif

%.o: %.cpp
	$(CXX) -c -g $< $(CFLAGS) $(STDFLAGS) $(OFLAGS) $(DFLAGS) $(WFLAGS) $(INCPATH) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
