/*======================================
created by Alex Tkachenkov & Niv Badichi
  ======================================*/

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = test_BattleShips  

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

rebuild: clean all
