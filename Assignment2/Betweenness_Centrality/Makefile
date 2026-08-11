CXX=g++
CXXFLAGS=-std=c++17 -O2

TARGET=betweennessCentrality.exe

SOURCES=driver.cpp betweennessCentrality.cpp

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	del /Q $(TARGET) 2>nul