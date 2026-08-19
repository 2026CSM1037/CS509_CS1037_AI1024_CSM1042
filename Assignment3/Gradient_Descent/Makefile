CXX=g++
CXXFLAGS=-std=c++17 -O2

TARGET=gradientDescent

SOURCES=driver.cpp gradientDescent.cpp

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	del /Q $(TARGET) 2>nul