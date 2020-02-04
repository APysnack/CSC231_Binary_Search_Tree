#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include "Definition.h"

class BSTNode {

public:
	Definition definition;
	BSTNode* left;
	BSTNode* right;

	BSTNode(Definition& definition, BSTNode* left = NULL, BSTNode* right = NULL) {
		this->definition = definition;
		this->left = left;
		this->right = right;
	}

	friend class BinarySearchTree;

private: 

};