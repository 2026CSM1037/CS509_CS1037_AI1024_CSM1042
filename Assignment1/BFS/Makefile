CXX = g++
CXXFLAGS = -O2 -std=c++17

TARGET = bfs_exec

all: $(TARGET)

$(TARGET): driver.cpp bfs.cpp bfs.h
	$(CXX) $(CXXFLAGS) driver.cpp bfs.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)