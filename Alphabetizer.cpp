#include "Alphabetizer.h"
#include "StringBST.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//default constructor for the Alphabetizer class
Alphabetizer::Alphabetizer(){

}

//defualt destructor for the Alphabetizer class
Alphabetizer::~Alphabetizer(){

}

//this function runs the program when onluy the executable is passed as a 
//command line argument. takes no parameters and returns nothing
void Alphabetizer::run(){
	string order;
	cin >> order;
	string added;
	cin >> added;
	while (!cin.eof())
	{
		stringbst.add(added);
		cin >> added;
	}
	
	if (order == "f")
	{
		cerr << "[ cin, f : ";
		printForward();
	}
	else if (order == "r")
	{
		cerr << "[ cin, r : ";
		printReverse();
	}
	
}

//this function runs the program when a filename and print order are passed
//as command line arguments. takes in the arguments(filename and order to print
//in) as parameters and returns nothing
void Alphabetizer::run(string filename, string order){
	ifstream instream;
	instream.open(filename.c_str());
	if(instream.fail())
	{
		cerr << "unable to open the file: "<< filename << endl;
		return;
	}
	string added;
	while (!instream.eof()){
		stringbst.add(added);
		instream >> added;	
	}
	instream.close();
	if (order == "r"){
		cerr << "[ "<< filename << ", r : ";
		printReverse();
	}
	if (order == "f"){
		cerr << "[ "<< filename << ", f : ";
		printForward();
	}
}

//this function prints the strings in the forward order. takes no parameters and
//returns nothing
void Alphabetizer::printForward(){
	cout << stringbst.getMin();
	stringbst.removeMin();
	while(stringbst.size() != 1)
	{
		cout << stringbst.getMin();
		cout << ", ";
		stringbst.removeMin();
	}
	cout << stringbst.getMin();
	stringbst.removeMin();
	
	cout << " ]";
}

//this function prints the strings in reverse order. takes no parameters and 
//returns nothing
void Alphabetizer::printReverse(){
	cout << stringbst.getMax();
	cout << ", ";
	stringbst.removeMax();
	while(stringbst.size() > 2)
	{
		cout << stringbst.getMax();
		cout << ", ";
		stringbst.removeMax();
	}
	cout << stringbst.getMax();
	stringbst.removeMax();
	
	cout << " ]";
}

