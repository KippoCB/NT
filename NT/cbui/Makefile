CXX = g++

CXXFLAGS = -I/data/data/com.termux/files/home/cbdent/NT -std=c++17 -fPIC $(shell pkg-config --cflags Qt5Widgets)
LDFLAGS = -shared
LDLIBS = $(shell pkg-config --libs Qt5Widgets)

TARGET = libcbui.so

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
