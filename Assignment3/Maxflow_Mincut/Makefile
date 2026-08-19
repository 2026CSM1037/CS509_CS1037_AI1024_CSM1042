CXX=g++
CXXFLAGS=-std=c++17 -O2

TARGET=maxflow

SOURCES=driver.cpp maxflow.cpp ../../shared/CSR/csr.cpp

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) -Wl,--stack,33554432

clean:
	del /Q $(TARGET) 2>nul