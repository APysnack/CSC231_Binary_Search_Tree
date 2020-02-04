#pragma once
#include "BSTNode.h"
#include <fstream>

class BinarySearchTree {
public: 
	// calls the private version of insert() and passes in definition with root pointer
	BinarySearchTree();
	void insert();
	void insert(Definition);
	void showInOrder();
	void displayTerm(string, BSTNode*&);
	void displayTerm(string);
	void search(string);
	void searchTree(string, BSTNode*&);
	void rewriteTxtFile(BSTNode*&);
	void rewriteTxtFile(BSTNode*&, Definition);
	void deleteTerm(string);
	void deleteTerm(string, BSTNode*&);
	void removeNode(BSTNode*&, string);
	void findKeyword(string, string);
	void findKeyword(string, string, BSTNode*&);
	BSTNode*& findMin(BSTNode*&);
	void flashCardsInOrder(BSTNode*&, bool);
	void flashCardsPreOrder(BSTNode*&);
	void flashCardsPostOrder(BSTNode*&);
	void flashCardsLevelOrder(BSTNode*&);
	void flashCardsInOrder();
	void flashCardsPreOrder();
	void flashCardsPostOrder();
	void flashCardsLevelOrder();
	void pressAnyKey();
	BSTNode*& getNodeIO(BSTNode*& tree);

private:
	// creates a node/pointer for the root
	BSTNode* root;
	void displayInOrder(BSTNode* tree) const;
	void insert(BSTNode*&, Definition);
};
