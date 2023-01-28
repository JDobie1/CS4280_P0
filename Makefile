CXX=g++
CXXFLAGS=-Wall -std=c++11
OBJ=main.o buildTree.o traversals.o
BIN=P0

%.o: %.cpp
    	$(CXX) -g $(CXXFLAGS) $< -c -o $@
$(BIN): $(OBJ)
        $(CXX) -g $(CXXFLAGS) $^ -o $@

clean:
        rm $(OBJ) $(BIN)
