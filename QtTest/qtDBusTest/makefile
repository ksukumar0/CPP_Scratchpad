CC=g++
CXX=g++
CFLAGS= -fstack-protector -fPIC
OFLAGS = -O2
STDFLAGS = -std=c++14
DFLAGS = -DQT_NO_VERSION_TAGGING

#VERBOSE=-v

QT_LIB_INSTALL_PATH = /usr/include/qt
QTDIRINC = /usr/include/qt
INCPATH = -I. -I$(QTDIRINC) -I$(QTDIRINC)/QtCore -I$(QTDIRINC)/QtDBus $(LIBS)

LD_FLAGS += -lQt5Core -lQt5DBus

ifdef WFLAGS
	${WFLAGS}
	WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .c,.o,$(SRC))

QT_DBUS_TEST = qtDBusTest.o

qtDBusTest: $(QT_DBUS_TEST)
	$(CXX) -o qtDBusTest $(VERBOSE) $(QT_DBUS_TEST) $(LD_FLAGS)
	@echo "Linking $<"

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(STDFLAGS) $(OFLAGS) $(DFLAGS) $(WFLAGS) $(INCPATH) $< -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
	rm qtDBusTest
