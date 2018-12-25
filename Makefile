CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3


Alphabetizer: Alphabetizer.o main.o StringBST.o
	${CXX} ${LDFLAGS} ${CXXFLAGS} Alphabetizer.o main.o StringBST.o \
	 -o Alphabetizer
	
main.o: Alphabetizer.h StringBST.h main.cpp
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c main.cpp
	
Alphabetizer.o: StringBST.h Alphabetizer.h Alphabetizer.cpp 
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c Alphabetizer.cpp
	
StringBST.o: StringBST.h StringBST.cpp
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c StringBST.cpp
	
clean:
	rm Alphabetizer *.o 
	
provide:
	provide comp15 hw4 main.cpp StringBST.h StringBST.cpp Alphabetizer.h \
	Alphabetizer.cpp README Makefile main.cpp testAlphabetizer.cpp \
	testStringBST.cpp
