#include <iostream>
#include <string>
#include "StringBST.h"

using namespace std;

//default constructor that initializes an empty bst
StringBST::StringBST(){
	root = NULL;
}

//costructor that takes an array and the size of the array as parameters, and
//initializes a correct bst with the information. Function returns nothing
StringBST::StringBST(string x[], int y){
	root = NULL;
	for(int i = 0; i < y; i++){
		add(x[i]);
	}
}

//destructor that deletes allocated memory in the heap using the clear function
StringBST::~StringBST(){
	clear();
}

//checks whether the tree has any nodes and returns a bool value that lets the
//client know whether or not the tree is empty
bool StringBST::isEmpty(){
	if (root == NULL){
		return true;
	}
	
	else
		return false;
}

//takes in a string, and a node pointer that would ideally point to the root of 
//the bst. The function creates a leaf and adds it to the bst of the root 
//passed as a paremeter. returns nothing
void StringBST::makeLeaf(string x, BSTNode *addMe){
	BSTNode *temp = NULL;
	temp -> name = x;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> count = 0;
	temp -> parent = addMe;
	if(addMe -> name > temp -> name){
		addMe -> left = temp; 
	}
	
	else if(addMe -> name < temp -> name){
		addMe -> right = temp; 
	}
}

//takes in a string and a node pointer. It creates a node pointed to by the 
//pointer passed as a parameter. Returns a pointer to the 
StringBST::BSTNode * StringBST::createNode(string x, BSTNode *node){
	node = new BSTNode;
	node -> name = x;
	node -> count = 1;
	node -> left = NULL;
	node -> right = NULL;
	node -> parent = NULL;
	return node;
}

//deletes all nodes from the binary search tree. Takes no parameters and returns
//nothing
void StringBST::clear(){
	postOrderDelete(root);
	root = NULL;
}

//helper function for the clear() function. It takes in a node pointer to a root
//as a parameter and deletes all nodes associated with the pointer. returns
//nothing

void StringBST::postOrderDelete(BSTNode *root){
	if (!root){
		return;
	}
	postOrderDelete(root -> left);
	postOrderDelete(root -> right);
	
	delete root;
}

//returns the size of the bst by calling sizeHelper function and takes no 
//parameters
int StringBST::size(){
	return sizeHelper(root);
}

//helper to the size function that takes a node ptr as a parameter, and returns
//the size of the bst.
int StringBST::sizeHelper(BSTNode *root){
        if (!root){
        	return 0;
        }
        	
        return root -> count+sizeHelper(root->left) + sizeHelper(root->right);
}

//helper function to get the max or min nodes in a bst. It takes in a node ptr
//and a string that lets it know to return either the max or min. It returns
//the min/max value in the bst associated to the ptr passed as a parameter
StringBST::BSTNode * StringBST::helpGetMaxMin(BSTNode* &root, string x){
	if (x == "MIN"){
		if(root -> left){
			return helpGetMaxMin(root -> left, x);
		}
		
		else{
			return root;
		}
	}
	else if(x == "MAX"){
		if(root -> right){
			return helpGetMaxMin(root -> right, x);
		}
		
		else{
			return root;
		}
	}
	return root;
}

//function that gets the max value using the helpgetmaxmin function. Takes in
//no parameters and returns the string value in the max node
string StringBST::getMax(){
	BSTNode *temp;
	string x = "MAX";
	temp = helpGetMaxMin(root, x);
	return temp -> name;
	
}

//function that gets the min value using the helpgetmaxmin function. Takes in
//no parameters and returns the string in the min node
string StringBST::getMin(){
	BSTNode *temp;
	string x = "MIN";
	temp = helpGetMaxMin(root, x);
	return temp -> name;
}

//this function returns the a pointer to the parent of the max node in the bst
//it takes in a node ptr associated with the bst as a parameter
StringBST::BSTNode * StringBST::getMaxNodeParent(BSTNode *x){
	if (x -> right && x -> right -> right){
			return getMaxNodeParent(x -> right);
	}
	
	else
		return x;
}

//this function returns the a pointer to the parent of the min node in the bst
//it takes in a node ptr associated with the bst as a parameter
StringBST::BSTNode * StringBST::getMinNodeParent(BSTNode *x){
	if(!root -> left && root -> right){
		x = NULL;
		return x;
	}
	else if(!root -> left){
		return root -> right;
	}
	else if(x -> left && x -> left -> left){
			return getMinNodeParent(x -> left);
	}
	else
		return x;
}

//this function removes an instance of the minimum value in the bst, and removes
//the whole node if there is only one instance of the minimum in the bst
//takes no parameters and returns nothing
void StringBST::removeMin(){
	BSTNode *temp;
	
	if (!root){
		throw runtime_error("empty_tree");
	}
	if(!root -> left && !root -> right){
		if(root -> count > 1){
			root -> count -= 1;
			return;
		}
		else{
			delete root;
			root = NULL;
			return;
		}
	}
	if(!root -> left && root -> right){
		BSTNode *hold = root;
		if(root -> count > 1){
			root -> count -= 1;
			return;
		}
		else{
			root = root -> right;
			delete hold;
			return;
		}
	}
	if(root) {
		temp = getMinNodeParent(root);
		if(temp && temp -> left -> count > 1){
			temp -> left -> count -= 1;
			return;
		}
		else{
			if(temp && !temp -> left -> right){
				delete temp -> left;
				temp -> left = NULL;
				return;
			}
			else{
				BSTNode *hold;
				hold = temp -> left;
				temp -> left = temp -> left -> right;
				delete hold;
				hold = NULL;
				return;	
			}
		}
	}
}

//this function removes an instance of the maximuim value in the bst, and 
//removes the whole node if there is only one instance of the maximum in the bst
//takes no parameters and returns nothing

void StringBST::removeMax(){
	BSTNode *temp;
	
	if (!root){
		throw runtime_error("empty_tree");
	}
	if(!root -> left && !root -> right){
		if(root -> count > 1){
			root -> count -= 1;
			return;
		}
		else{
			delete root;
			root = NULL;
			return;
		}
	}
	if(!root -> right && root -> left){
		BSTNode *hold = root;
		if(root -> count > 1){
			root -> count -= 1;
			return;
		}
		else{
			root = root -> left;
			delete hold;
			return;
		}
	}
	if(root) {
		temp = getMaxNodeParent(root);
		if(temp && temp -> right -> count > 1){
			temp -> right -> count -= 1;
			return;
		}
		else{
			if(temp && !temp -> right -> left){
				delete temp -> right;
				temp -> right = NULL;
				return;
			}
			else{
				BSTNode *hold;
				hold = temp -> right;
				temp -> right = temp -> right -> left;
				delete hold;
				hold = NULL;
				return;	
			}
		}
	}	
}


//helper function for the contains function that takes a string and a node ptr
//to the bst. It compares its string parameter with the strings contained in the
//nodes of its bst and returns true if there is a node string that matches its
//string, and false otherwise
bool StringBST::nestingDoll(string check, BSTNode *x){
	if(x){
		if(x -> name == check){
			return true;
		}
		
		else{
			if(x -> left){
				nestingDoll(check, x -> left);
			}
			
			if(x -> right){
				nestingDoll(check, x -> right);
			}
		}
	}
	return false;
}

//this function takes in a string as a parameter and uses the nesting doll
//helper function to check if its string parameter is contained in the bst. It 
//returns true if it is, and false otherwise
bool StringBST::contains(string x){
	return nestingDoll(x, root);
}

//prints the bst by passing in the root as a parameter to the printHelp helper
//function in order to print out the bst. Takes no parameters and returns
//nothing
void StringBST::print(){
    	printHelp(root);
}

//helper function that takes in a node ptr as a parameter and prints out the 
//strings in the bst nodes of the bst. Returns nothing.
void StringBST::printHelp(BSTNode *p){
	if (!p){
		return;
	}
	
	cout << "[";
    	if(p != NULL){
        	if(p->left){
        		printHelp(p->left);
        	}
        
       		else{
        		cout << "[]";
        	}
        
        	cout<<" "<< p -> name <<" " << p -> count << " ";
        
        	if(p->right){
        		printHelp(p -> right);
        	}
        
        	else
        		cout << "[]";
    	}
    	
    else{
    
    	return;
    }
    cout << "]";
}

//takes in a string as a value and adds it to the bst by passing the root of 
//its bst to the addhelper function. Returns nothing.
void StringBST::add(string x){
	addHelper(root, x);
}

//takes in the address of a node ptr, and a string. Then adds the string to the
//bst associated with the node ptr. Returns nothing
void StringBST::addHelper(BSTNode* &root, string value)
{
     	if (!root) {
          	root = createNode(value, root);
     	}
  
     	else if(value == root -> name){
		root -> count += 1;
		return;	
	} 	
     	else if (value < root -> name) {
          	addHelper(root->left, value);
     	}
     	
     	else if (value > root -> name) {
          	addHelper(root->right, value);
     	}
}

//takes in a string and removes an instance of it from the bst by passing the 
//string and root into the removehelp helper function. returns a bool that lets
//the client know whether or not the string was found and removed	
bool StringBST::remove(string x){
	return removeHelp(x, root);
}

//helper function that takes in a string and the address to a node ptr and 
//removes an instance of the string from the bst associated with the node ptr
bool StringBST::removeHelp(string x, BSTNode * &root){
	if(!root)
		return false; 
	if(root -> name == x){
		if(root -> count > 1){
			root -> count -= 1;
			return true;
		}
		else{	
			if(root -> right && root -> left)
				return removeRootTwoKids(root);			
			else if(!root -> right && root -> left)
				return removeRootNoRight(root);
			else if (!root -> right && !root -> left)
				return removeRootNoKids(root);		
		}	
	}
	if(root -> right && root -> right -> name == x)
		return removeFromRight(root -> right);
	if(root -> left && root -> left -> name == x)
		return removeFromLeft(root -> left);
	if(root -> left)
		removeHelp(x, root -> left);
	if(root -> right)
		removeHelp(x, root -> right);
		
	return false;
}	

//this function returns the node with the smallest value associated with the
//right child of the node passed as the root. It takes a node ptr as a parameter		
StringBST::BSTNode * StringBST::recurseRightLeftMost(BSTNode *temp){
	if(temp -> left){
		return recurseRightLeftMost(temp -> left);
	}
	
	else
		return temp;
}	

//this function returns the node with the smallest value associated with the
//left child of the node passed as the root. It takes a node ptr as a parameter	
StringBST::BSTNode * StringBST::recurseLeftRightMost(BSTNode *temp){
	if(temp -> right){
		return recurseLeftRightMost(temp -> right);
	}
	
	else
		return temp;
}

//this function removes an instance of the left child of a parent passed as a 
//parameter and returns a bool value that lets the client know whether or not 
//the instance was successfully removed.
bool StringBST::removeFromLeft(BSTNode *x){
	if(x -> left -> count > 1){
		x -> left -> count -= 1;
		return true;
	}
	else{
		if(x -> left -> right){
			BSTNode *hold;
			hold = x -> left;
			x -> left = x -> left -> right;
			delete hold;
			hold = NULL;
			return true;
		}
			
		if(root -> left -> left){
			BSTNode *hold;
			hold = x -> left;
			x -> left = x -> left -> left;
			delete hold;
			hold = NULL;
			return true;
		}
	}
	return true;
}

//this function removes an instance of the right child of a parent passed as a 
//parameter and returns a bool value that lets the client know whether or not 
//the instance was successfully removed.
bool StringBST::removeFromRight(BSTNode *x){
		if(x -> right -> count > 1){
			x -> right -> count -= 1;
			return true;
		}
		else{
			if(x -> right -> right){
				BSTNode *hold;
				hold = root -> right;
				x -> right = x -> right -> right;
				delete hold;
				hold = NULL;
				return true;
			}
			
			if(x -> right -> left){
				BSTNode *hold;
				hold = x -> right;
				x -> right = x -> right -> left;
				delete hold;
				hold = NULL;
				return true;
			}
		}
		return true;
}

//this function removes an instance of a root that has bot a left and right 
//child in a bst. It takes a node ptr to the root as a parameter and returns 
//a bool value that lets the client know whether or not the root was 
//successfully removed.
bool StringBST::removeRootTwoKids(BSTNode *x){

	BSTNode *temp = recurseRightLeftMost(x -> right);
	x -> name = temp -> name;
	x -> count = temp -> count;
	delete temp;
	temp = NULL;
	x -> right = NULL;
	return true;
}

//this function removes an instance of a root that has a left but no right 
//child in a bst. It takes a node ptr to the root as a parameter and returns 
//a bool value that lets the client know whether or not the root was 
//successfully removed.	
bool StringBST::removeRootNoRight(BSTNode *x){
	BSTNode *hold;
	BSTNode *temp;
	hold = x;
	temp = recurseLeftRightMost(x -> left);
	x = temp;
	delete temp;
	delete hold;
	hold = NULL;
	temp = NULL;
	return true;
}

//this function removes an instance of a root that has no left or right 
//children in a bst. It takes a node ptr to the root as a parameter and returns 
//a bool value that lets the client know whether or not the root was 
//successfully removed.
bool StringBST::removeRootNoKids(BSTNode *x){
	delete x;
	x = NULL;
	return true;
}
