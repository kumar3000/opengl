CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror
CXXLIBS = -lGL -lGLU -lglut

main: src/main.cpp
	$(CXX) $(CXXFLAGS) -o bin/main src/main.cpp $(CXXLIBS)

.PHONY: clean
clean:
	rm -f bin/main

.PHONY: run
run:
	bin/main
