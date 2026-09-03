# Subdirectory Makefile

TARGET ?= setup

CXX := g++

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# Headers only
CPPFLAGS := -I..

# Compile flags
CXXFLAGS := -std=c++17 -Wall -Wextra $(CPPFLAGS)

# Qt flags
QT_CFLAGS := $(shell pkg-config --cflags Qt5Widgets Qt5X11Extras)
QT_LIBS   := $(shell pkg-config --libs Qt5Widgets Qt5X11Extras)

# Library search paths + libs 
LDFLAGS := -L../cbui -L../cbutil -lcbui -lcbutil $(QT_LIBS)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
