CXX = g++

CXXFLAGS = -I/data/data/com.termux/files/home/cbdent/NT -std=c++17 -fPIC
LDFLAGS = -shared
LDLIBS = ../cbui/libcbui.so ../cbutil/libcbutil.so

TARGET = libcbdiags.so

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
