#include "StringBST.h"
#include "Alphabetizer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]){
	string direction, filename;
	Alphabetizer begin;
	if (argc != 3 && argc != 1){
		cerr << "Usage: alphabetizer [order filename]" << endl;
		return 1;
	}
	if(argc == 3){
		if(strcmp(argv[1],"f") != 0 && strcmp(argv[1],"r") != 0){
		cerr << "Usage: alphabetizer [order filename]" << endl;
		return 1;
		}
		direction = argv[1];
		filename = argv[2];
		begin.run(filename, direction);
	}
	else if(argc == 1)
		begin.run();
	return 0;
}

