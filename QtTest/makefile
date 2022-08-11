CXX=g++
CFLAGS = -fstack-protector-strong -fPIC -fsanitize=address
OFLAGS = -O2
STDFLAGS = -std=c++14

DFLAGS = -DQT_NO_VERSION_TAGGING

QT_LIB_INSTALL_PATH = /opt/ArtifactCache/Qt/ubu18-04_x64/5.15.2/lib/
QTDIRINC = /opt/ArtifactCache/Qt/ubu18-04_x64/5.15.2/include
INCPATH = -I. -I$(QTDIRINC) -I$(QTDIRINC)/QtCore

#LDFLAGS = -Wl,-rpath,$(QT_LIB_INSTALL_PATH)
#LDFLAGS += ${QT_LIB_INSTALL_PATH}/libQt5Core.so -lpthread

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
	$(CXX) -o test $(LDFLAGS) $(TEST_OBJS) $(LIBS)

fileLen: $(FILELENGTH_OBJS)
	$(CXX) -o fileLen $(LDFLAGS) $(FILELENGTH_OBJS) $(LIBS)

QlibTest: $(QLIBTEST_OBJS)
	$(CXX) -o QlibTest $(LDFLAGS) $(QLIBTEST_OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) -c -g $< $(CFLAGS) $(STDFLAGS) $(OFLAGS) $(DFLAGS) $(WFLAGS) $(INCPATH) -o $@
	@echo "CC $<"

clean:
	rm -rf *.o
