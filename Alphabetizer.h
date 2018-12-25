#ifndef ALPHABETIZER_H_
#define ALPHABETIZER_H_
#include "StringBST.h"
#include <fstream>

class Alphabetizer{

	public:
		//default constructor
		Alphabetizer();
		
		//destructor
		~Alphabetizer();
		
		//handles running when there are no command line arguments
		void run();
		
		//handles running when there are command line argumenst
		void run(std::string filename, std::string order);
	
	
	
	
	
	private:
		
		//an instance of the StringBST class	
		StringBST stringbst;
		
		//function for printing in forward direction
		void printForward();
		
		//function for printing in reverse direction
		void printReverse();
		
		
	
	

};
#endif
