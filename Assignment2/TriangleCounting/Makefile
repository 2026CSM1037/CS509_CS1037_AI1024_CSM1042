CXX = g++
ASSIGN01_DIR = C:/Users/Asus/Desktop/CS509_CSM1042/assignment_01
CXXFLAGS = -O2 -std=c++17 -Iinclude -I$(ASSIGN01_DIR)/include

all: bin/assignment2 bin/generate_graph

bin/assignment2: src/main.cpp src/triangle_counting.cpp $(ASSIGN01_DIR)/src/graph/graph.cpp $(ASSIGN01_DIR)/src/helper/csr_helper.cpp
	if not exist bin mkdir bin
	$(CXX) $(CXXFLAGS) -o bin/assignment2 src/main.cpp src/triangle_counting.cpp $(ASSIGN01_DIR)/src/graph/graph.cpp $(ASSIGN01_DIR)/src/helper/csr_helper.cpp

bin/generate_graph: generator/generate_graph.cpp
	if not exist bin mkdir bin
	$(CXX) $(CXXFLAGS) -o bin/generate_graph generator/generate_graph.cpp

clean:
	if exist bin rmdir /s /q bin