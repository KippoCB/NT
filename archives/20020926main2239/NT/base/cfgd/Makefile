CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -lQt5Core

QT_CFLAGS := $(shell pkg-config --cflags Qt5Core)
QT_LIBS   := $(shell pkg-config --libs Qt5Core)


TARGET = cfgd

SRC = main.cpp cfgd.cpp

all:
	$(CXX) $(CXXFLAGS) $(QT_CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
