CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = p04_code_analyzer
SRCS = main.cpp code_analyzer.cpp Variable.cpp Loop.cpp Comment.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)