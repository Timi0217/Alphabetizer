#include <iostream>
#include <string>
#include "StringBST.h"

using namespace std;
//test 1
/*
int main(){
	string test[6] = {"Ram","Horse", "Horse", "Horse", "Swan", "Swan"};
	StringBST check(test, 6);
	check.print();
	cerr << "about to remove max" << endl;
	check.removeMax();
	check.print();
	cout << endl;
	cerr << "max removed" << endl;
	cerr << "about to remove max" << endl;
	check.removeMax();
	check.print();
	cout << endl;
	cerr << "about to remove max" << endl;
	check.removeMax();
	check.print();
	cout << endl;
	int sizeAfter = check.size();
	cout << sizeAfter << endl;
	string y;
	y = check.getMin();
	cout << y <<": Im min"<< endl;
	check.removeMin();
	cerr << "min removed" << endl;
	cerr << "removed min 1" << endl;
	check.print();
	check.removeMin();
	cerr << "min removed" << endl;
	cerr << "removed min 2" << endl;
	check.print();
return 0;
}
*/


//issue with clear() -- fixed



//test 2
int main(){

	string test[6] = {"Ram","Horse", "Horse", "Horse", "Swan", "Swan"};
	StringBST check(test, 6);
	cerr << "printing" << endl;
	check.print();
	cout << endl;
	int x = check.size();
	cout << x << endl;
	string y = check.getMin();
	cout << y <<": Im min"<< endl;
	string z = check.getMax();
	cout << z <<": Im max"<< endl;
	if(check.contains("Ram") == true){
		cout << "yeah" << endl;
	}
	bool removeCheck = check.remove("Kingfisher");
	if (removeCheck == false){
		cout << "It's false" << endl;
	}
	check.print();
	cout << endl;
	cout << endl;
	check.remove("Ram");
	check.print();
	cout << endl;
	int newsize = check.size();
	cout << newsize << endl;
return 0;
}

