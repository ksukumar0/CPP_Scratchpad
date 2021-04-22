CXX=g++
CFLAGS = -fstack-protector-strong -fPIC -fsanitize=address
OFLAGS = -O2
STDFLAGS = -std=c++14

DFLAGS = -DQT_NO_VERSION_TAGGING

QT_LIB_INSTALL_PATH = /opt/ArtifactCache/Qt/ubu18-04_x64/5.15.2/lib/
QTDIRINC = /opt/ArtifactCache/Qt/ubu18-04_x64/5.15.2/include
INCPATH = -I. -I$(QTDIRINC) -I$(QTDIRINC)/QtCore

#LD_LIBRARY_PATH+=/opt/ArtifactCache/Qt/ubu18-04_x64/5.15.2/lib

#LDFLAGS = -Wl,-rpath,$(QT_LIB_INSTALL_PATH)
#LDFLAGS += ${QT_LIB_INSTALL_PATH}/libQt5Core.so -lpthread

LDFLAGS += -fsanitize=address -v
LIBS += -L${QT_LIB_INSTALL_PATH}
LIBS += -lQt5Core

ifndef WFLAGS
#WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .cpp,.o,$(SRC))

TEST_OBJS = test.o
FILELENGTH_OBJS = fileLength.o

test: $(TEST_OBJS)
	$(CXX) -o test $(LDFLAGS) $(TEST_OBJS) $(LIBS)

fileLen: $(FILELENGTH_OBJS)
	$(CXX) -o fileLen $(LDFLAGS) $(FILELENGTH_OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) -c -g $< $(CFLAGS) $(STDFLAGS) $(OFLAGS) $(DFLAGS) $(WFLAGS) $(INCPATH) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
