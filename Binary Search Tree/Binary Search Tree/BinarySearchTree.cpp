#pragma once
#include "BinarySearchTree.h"
#include <fstream>
#include <iostream>
#include <conio.h>

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

void BinarySearchTree::insert() {
	return;
}

void BinarySearchTree::insert(Definition definition) {
	insert(root, definition);
}


void BinarySearchTree::insert(BSTNode*& tree, Definition newDefinition) {

	// Base Case 1
	//checks to see if the node is empty 
	if (tree == NULL) {

		// creates new node in binary search tree, initializes L and R pointers to null and stores definition
		tree = new BSTNode(newDefinition);
		return;
	}

	// Base Case 2
	// if the definition is already stored in the binary search tree, return
	if (newDefinition.getWord() == tree->definition.getWord()) {
		return;
	}

	// if the new definition is less than the definition in the stored node, recursive call to move left
	// should be LESS THAN return value
	if (newDefinition.getWord() < tree->definition.getWord()) {
		insert(tree->left, newDefinition);
	}

	// if the new definition is greater than the definition in the stored node, recursive call to move right
	else {
		insert(tree->right, newDefinition);
	}

}

void BinarySearchTree::displayInOrder(BSTNode* tree) const {
	if (tree == NULL) {
		return;
	}
	else {
		displayInOrder(tree->left);
		cout << tree->definition.getWord() << " " << endl;
		displayInOrder(tree->right);
	}
}

void BinarySearchTree::showInOrder() {
	displayInOrder(root);
}

void BinarySearchTree::search(string searchTerm) {
	searchTree(searchTerm, root);
}


void BinarySearchTree::searchTree(string searchTerm, BSTNode*& tree) {
	
	if (tree == NULL) {
		return;
	}

	if (searchTerm == tree->definition.getWord()) {
		string newDefinition;
		cout << "Please enter a new definition for " << tree->definition.getWord() << endl;
		cin.ignore();
		getline(cin, newDefinition);
		tree->definition.setDefinition(newDefinition);
		rewriteTxtFile(root, tree->definition);
	}
	
	if (searchTerm < tree->definition.getWord()) {
		searchTree(searchTerm, tree->left);
	}

	if (searchTerm > tree->definition.getWord()) {
		searchTree(searchTerm, tree->right);
	}

}

void BinarySearchTree::rewriteTxtFile(BSTNode*& tree, Definition newDefinition) {

	remove("List.txt");

	ofstream outFile;

	if (tree == NULL) {
		tree = new BSTNode(newDefinition);
		return;
	}
	else {
		fstream file("List.txt", ios::in | ios::out | ios::app);
		if (!file.is_open()) {
			cout << "error while opening the file" << endl;
		}

		rewriteTxtFile(tree->left);

		file << tree->definition.getWord() << endl;
		file << tree->definition.getDefinition() << endl;

		rewriteTxtFile(tree->right);
		outFile.close();
	}
}

void BinarySearchTree::rewriteTxtFile(BSTNode*& tree) {

	ofstream outFile;

	if (tree == NULL) {
		return;
	}
	else {
		fstream file("List.txt", ios::in | ios::out | ios::app);
		if (!file.is_open()) {
			cout << "error while opening the file" << endl;
		}

		rewriteTxtFile(tree->left);

		file << tree->definition.getWord() << endl;
		file << tree->definition.getDefinition() << endl;

		rewriteTxtFile(tree->right);
		outFile.close();
	}
}

void BinarySearchTree::displayTerm(string searchTerm) {
	displayTerm(searchTerm, root);

}

void BinarySearchTree::displayTerm(string searchTerm, BSTNode*& tree) {
	if (tree == NULL) {
		return;
	}

	if (searchTerm == tree->definition.getWord()) {
		cout << "The word you searched for is: " << tree->definition.getWord() << endl;
		cout << "This word is defined as: " << tree->definition.getDefinition() << endl;


	}

	if (searchTerm < tree->definition.getWord()) {
		displayTerm(searchTerm, tree->left);
	}

	if (searchTerm > tree->definition.getWord()) {
		displayTerm(searchTerm, tree->right);
	}

}

void BinarySearchTree::deleteTerm(string searchTerm) {
	deleteTerm(searchTerm, root);
}

void BinarySearchTree::deleteTerm(string searchTerm, BSTNode*& treeNode) {
	if (treeNode == NULL) {
		return;
	}

	if (searchTerm == treeNode->definition.getWord()) {
		removeNode(treeNode, searchTerm);
		remove("List.txt");
		rewriteTxtFile(root);
		cout << "Term Deleted!" << endl;
		return;
	}

	if (searchTerm < treeNode->definition.getWord()) {
		deleteTerm(searchTerm, treeNode->left);
	}

	if (searchTerm > treeNode->definition.getWord()) {
		deleteTerm(searchTerm, treeNode->right);
	}
}

void BinarySearchTree::removeNode(BSTNode*& treeNode, string searchTerm) {
	// Case 1: No Children
	if (treeNode->left == NULL && treeNode->right == NULL) {
		delete treeNode;
		treeNode = NULL;
	}

	// Case 2: 1 Child

	// Has a child on the left
	else if (treeNode->right == NULL) {
		BSTNode* temp = treeNode;
		treeNode = treeNode->left;
		delete temp;
	}

	// Has a child on the right
	else if (treeNode->left == NULL) {
		BSTNode* temp = treeNode;
		treeNode = treeNode->right;
		delete temp;
	}

	// Case 3: 2 children
	else {
		BSTNode* temp = findMin(treeNode->right);
		treeNode->definition = temp->definition;
		temp = treeNode->right;
		treeNode->right = treeNode->right->right;
		if (treeNode->right != NULL) {
			treeNode->right->left = treeNode;
		}
		delete temp;
	}
}

BSTNode*& BinarySearchTree::findMin(BSTNode*& treeNode) {
	BSTNode* tempNode = treeNode;
	while (tempNode->left != NULL) {
		tempNode = tempNode->left;
	}

	return tempNode;
}

void BinarySearchTree::findKeyword(string keyword, string lcKeyword) {
	findKeyword(keyword, lcKeyword, root);
}

void BinarySearchTree::findKeyword(string keyword, string lcKeyword, BSTNode*& treeNode) {
	if (treeNode == NULL) {
		return;
	}
	
	if (treeNode->definition.getWord().find(keyword) != string::npos ||
		treeNode->definition.getDefinition().find(keyword) != string::npos ||
		treeNode->definition.getWord().find(lcKeyword) != string::npos ||
		treeNode->definition.getDefinition().find(lcKeyword) != string::npos) {
		
		cout << endl << treeNode->definition.getWord() << endl <<
			treeNode->definition.getDefinition() << endl;


		}

	findKeyword(keyword, lcKeyword, treeNode->left);
	findKeyword(keyword, lcKeyword, treeNode->right);

	}

void BinarySearchTree::flashCardsInOrder(BSTNode*& tree, bool keepGoing) {
	char userInput = 'Y';

	while (keepGoing) {
		if (tree->left != NULL) {
			flashCardsInOrder(tree->left, keepGoing);
		}

		cout << tree->definition.getWord() << endl;

		cout << "Would you like to keep going? Y/N: " << endl;
		cin >> userInput;
		if (userInput == 'N' || userInput == 'n') {
			keepGoing = false;
		}

		if (tree->right != NULL) {
			flashCardsInOrder(tree->right, keepGoing);
		}
	}
}

void BinarySearchTree::flashCardsPreOrder(BSTNode*& tree) {

}
void BinarySearchTree::flashCardsPostOrder(BSTNode*& tree) {

}
void BinarySearchTree::flashCardsLevelOrder(BSTNode*& tree) {

}

void BinarySearchTree::flashCardsInOrder() {
	bool keepGoing = true;
	flashCardsInOrder(root, keepGoing);
}

void BinarySearchTree::flashCardsPreOrder() {
	flashCardsPreOrder(root);
}

void BinarySearchTree::flashCardsPostOrder() {
	flashCardsPostOrder(root);
}

void BinarySearchTree::flashCardsLevelOrder() {
	flashCardsLevelOrder(root);
}

void BinarySearchTree::pressAnyKey() {
	cout << endl << "Press any key to see the definition" << endl;
	_getch();
}

BSTNode*& BinarySearchTree::getNodeIO(BSTNode*& treeNode) {
	BSTNode* tempNode = treeNode;
	while (tempNode->left != NULL) {
		tempNode = tempNode->left;
	}

	return tempNode;
}