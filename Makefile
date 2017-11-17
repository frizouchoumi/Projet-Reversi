CXXFLAGS= -std=c++11 -w

all : Case.cpp
	g++ $(CXXFLAGS) Case.cpp -o Case
