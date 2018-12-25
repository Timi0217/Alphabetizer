/*Oluwatimilehin Dayo-Kayode
 *StringBST header file
 */
 
 #ifndef STRINGBST_H_
 #define STRINGBST_H_
 #include <iostream>
 
 class StringBST{
 
 	public:
 	
 		//default constructor initializes an empty bst
 		StringBST();
 		
 		//creates a bst with the strings in the array inserted in the
 		//order they appear, int specifies the size of the array
 		StringBST(std::string x[], int y);
 		
 		
 		//destructor
 		~StringBST();
 		
 		//returns boolean that lets client know whether or not the 
 		//instance of the StringBST is empty
 		bool isEmpty(); 
 		
 		//makes the current bst into an empty bst
 		void clear();	
 		
 		//returns the number of strings in a bst(takes duplicates into
 		//account
 		int size();
 		
 		//prints the bst in order
 		void print();
 		
 		//adds its parameter to the bst
 		void add(std::string x);
 		
 		//finds and removes an instance of the parameter passed in the 
 		//bst. returns tree if instance found and false otherwise
 		bool remove(std::string x);
 		
 		//returns the leftmost(smallest) string in a bst. throws
 		//runtime_error exception if empty with the message "empty_tree"
 		std::string getMin();
 		
 		//returns the rightmost(largest) string in a bst. throws
 		//runtime_error exception if empty with the message "empty_tree"
 		std::string getMax();
 		
 		//removes an instane of the leftmost(smallest) string in a bst. 
 		//throws runtime_error exception if empty with the message 
 		//"empty_tree"
 		void removeMin();
 		
 		//removes an instane of the rightmost(biggest) string in a bst. 
 		//throws runtime_error exception if empty with the message 
 		//"empty_tree"
 		void removeMax();
 		
 		//checks to see if a bst contains the parameter passed in and 
 		//returns a bool to let the client know whether or not it was
 		//found
 		bool contains(std::string x);

 	
 	private:
 		
 		//declaration of the struct for the nodes in the bst
        	struct BSTNode {
        		std::string name;
			BSTNode *left;
			BSTNode *right;
			BSTNode *parent;
			int count;
       		};
       		
       		//a node ptr to the root of the bst
        	BSTNode *root;
        	
        	//expand the bst to accomodate more nodes
        	void expand();
        	
        	//return curr size of the bst
        	int currSize;
        	
        	//helper function to return the current size of the bst
        	int sizeHelper(BSTNode *root);
        	
        	//function to add nodes to the bst
        	void addHelper(BSTNode * &addMe, std::string x);
        	
        	//creates a root for the bst
        	BSTNode * createNode(std::string x, BSTNode *ptr);
        	
        	//makes a leaf
        	void makeLeaf(std::string x, BSTNode *addMe);
        	
        	//delete all nodes 
        	void postOrderDelete(BSTNode *root);
        	
        	//return the rightmost leaf on the left side
        	BSTNode *rightMost(BSTNode *root);
        	
        	//return the leftmost leaf on the right side
        	BSTNode * leftMost(BSTNode *root);
        	
        	//return the smallest nodes parent
        	BSTNode * getMinNodeParent(BSTNode *x);
        	
        	//returns the biggest nodes parent
        	BSTNode * getMaxNodeParent(BSTNode *x);
        	
        	//compares its string parameter to the strings in all nodes in 
        	//the bst
        	bool nestingDoll(std::string check, BSTNode *x);
        	
        	//helper function for the print function
        	void printHelp(BSTNode* p);
        	
        	//helper for getting either the min or max value in the tree
        	BSTNode * helpGetMaxMin(BSTNode * &root, std::string x);
        	
        	//helper function to remove a node or frequency of it
        	bool removeHelp(std::string, BSTNode * &temp);
        	
        	//recurses to the biggest node in the subtrees of the roots 
        	//left child
        	BSTNode * recurseLeftRightMost(BSTNode *temp);
        	
        	//recurses to the biggest node in the subtrees of the roots
        	//right child
        	BSTNode * recurseRightLeftMost(BSTNode *temp);
        	
        	//remove the leftmost leaf associated with a parent node 
        	bool removeFromLeft(BSTNode *x);
        	
        	//remove the rightmost leaf associated with a parent node 
        	bool removeFromRight(BSTNode *x);
        	
        	//remove a root that has no right child
        	bool removeRootNoRight(BSTNode *x);
        	
        	//removes a root with two children
        	bool removeRootTwoKids(BSTNode *x);
        	
        	//removes a root with no children
        	bool removeRootNoKids(BSTNode *x);
 };
 #endif
