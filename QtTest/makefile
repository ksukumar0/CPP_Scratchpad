CXX=g++
CFLAGS = -fstack-protector-strong -fPIC -fsanitize=address
OFLAGS = -O2
STDFLAGS = -std=c++14

DFLAGS = -DQT_NO_VERSION_TAGGING

#QT_LIB_INSTALL_PATH = /opt/ArtifactCache/Qt/ubu18-04_x64/5.15.2/lib/
QT_LIB_INSTALL_PATH = /usr/include/x86_64-linux-gnu/qt5/QtCore
QTDIRINC = /usr/include/x86_64-linux-gnu/qt5
INCPATH = -I. -I$(QTDIRINC) -I$(QTDIRINC)/QtCore

#LDFLAGS = -Wl,-rpath,/lib/x86_64-linux-gnu/
LDFLAGS += -lQt5Core -lpthread

LIBS += -L${QT_LIB_INSTALL_PATH}
LD_LIBRARY_PATH += /home/sukumar/Projects/ESMAIN/sukumar_ES-MAIN_21.4.12.0_view/Build/clang_x64/bin/binDebug/

LDFLAGS += -fsanitize=address
#LDFLAGS += -v
LIBS += -L${QT_LIB_INSTALL_PATH}
LIBS += -lQt5Core -ldl


ifndef WFLAGS
#WFLAGS= -Werror -Wall
endif

SRC = $(wildcard *.c)
OBJS=$(subst .cpp,.o,$(SRC))

TEST_OBJS = test.o
FILELENGTH_OBJS = fileLength.o
QLIBTEST_OBJS = QlibTest.o

test: $(TEST_OBJS)
ifeq ($(CXX),g++)
	$(CXX) -o test $(TEST_OBJS) $(LDFLAGS)
else
	$(CXX) -o test $(LDFLAGS) -lstdc++ $(TEST_OBJS)
endif

fileLen: $(FILELENGTH_OBJS)
ifeq ($(CXX),g++)
	$(CXX) -o fileLen $(LDFLAGS) $(FILELENGTH_OBJS)
else
	$(CXX) -o fileLen $(LDFLAGS) -lstdc++ $(FILELENGTH_OBJS)
endif

QlibTest: $(QLIBTEST_OBJS)
	$(CXX) -o QlibTest $(LDFLAGS) $(QLIBTEST_OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) -c -g $< $(CFLAGS) $(STDFLAGS) $(OFLAGS) $(DFLAGS) $(WFLAGS) $(INCPATH) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
