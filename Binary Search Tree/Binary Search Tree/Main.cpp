#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>

#include "BinarySearchTree.h"
#include "BSTNode.h"
#include "Definition.h"


using namespace std;
void openFileDefinitions(BinarySearchTree&);
void pressAnyKey();
bool showMenu(BinarySearchTree&);
void traversalMenu(BinarySearchTree&);
static bool keepGoing = true;
string wordFormat(string&);
string lowerCaseFormat(string);

int main() {

	BinarySearchTree newTree;

	openFileDefinitions(newTree);

	while (keepGoing) {
		keepGoing = showMenu(newTree);
	}


	return 0; 
}

void openFileDefinitions(BinarySearchTree& tree) {
	ifstream inFile;
	inFile.open("List.txt");

	if (inFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	int count = 0;
	Definition newDefinition;

	while (!inFile.eof()) {
		string word, definition, str;

		string line;
		getline(inFile, line);
		word = line;
		getline(inFile, line);
		definition = line;
		newDefinition.setWord(word);
		newDefinition.setDefinition(definition);

		tree.insert(newDefinition);
	}

	inFile.close();
}

bool showMenu(BinarySearchTree& newTree) {
	// function variables
	char userInput;
	bool reprompt = true;
	bool endprogram = false;
	int choice;

	// outputs list with options for user to choose from
	cout << endl
		<< "---------------------------------------------------------------------\n"
		<< " Select an option from the menu below\n"
		<< " by entering the number of the choice\n"
		<< "---------------------------------------------------------------------\n"
		// complete
		<< "\t1\tAdd a new term and definition to the list\n"

		// complete
		<< "\t2\tEdit a term on the list\n"

		// complete
		<< "\t3\tFind and display a term from the list\n"

		// complete
		<< "\t4\tDisplay all terms in the list\n"

		// 
		<< "\t5\tShow flashcards\n"

		// complete
		<< "\t6\tDelete a term from the list\n"

		// complete
		<< "\t7\tShow all entries containing a particular search string\n"

		// complete
		<< "\t8\tEnd program\n"
		<< "---------------------------------------------------------------------\n\n"
		<< "Enter your choice : \n\n";

	// switch statement that executes the case matching the user's input
	cin >> choice;
	switch (choice) {


	case 1: {
		string word, definition;

		cout << "Please enter the word that you would like to define: " << endl;
		cin >> word;
		cin.ignore();
		cout << "Please enter a brief definition of the word " << word << endl;
		getline(cin, definition);

		word = wordFormat(word);

		cout << word;
		cout << definition;

		Definition newDefinition(word, definition);

		fstream file("List.txt", ios::in | ios::out | ios::app);
		if (!file.is_open()) {
			cout << "error while opening the file" << endl;
		}

		file << word << endl;
		file << definition << endl;


		newTree.insert(newDefinition);

		break;
	}

	case 2: {
		string searchTerm;
		cout << "Please enter the term you would like to edit" << endl;
		cin >> searchTerm;
		searchTerm = wordFormat(searchTerm);

		newTree.search(searchTerm);

		break;
	}

	case 3: {
		string searchTerm;
		cout << "Please enter the term you would like to search for" << endl;
		cin >> searchTerm;

		searchTerm = wordFormat(searchTerm);

		newTree.displayTerm(searchTerm);

		break;
	}

	case 4: {
		cout << endl << "These are all of the terms currently in the list" << endl << endl;
		newTree.showInOrder();
		break;
	}
	
	case 5: {
		traversalMenu(newTree);
		break;
	}

	case 6:{
		string searchTerm;
		cout << "Please enter the term you would like to delete from the list" << endl;
		cin >> searchTerm;

		searchTerm = wordFormat(searchTerm);

		newTree.deleteTerm(searchTerm);
		break;
	}

	case 7: {
		string searchTerm, lcSearchTerm;
		cout << "Please enter the keyword that you would like to search for (e.g. \"to\"): " << endl;
		cin >> searchTerm;
		searchTerm = wordFormat(searchTerm);
		lcSearchTerm = lowerCaseFormat(searchTerm);


		cout << endl << "Word(s) matching your search: " << endl
			<< "-----------------------------------" << endl;

		newTree.findKeyword(searchTerm, lcSearchTerm);
		break; 
	}

	case 8: {
		cout << endl << "Goodbye" << endl;
		userInput = 'n';
		endprogram = true;
		break;
	}

		// handles the exception in case the user input does not match one of the cases
	default: {
		cout << "That option is currently not available\n";
		pressAnyKey();
		break;} // end default
	} // end switch

	  // prompts the user asking if they'd like to see the menu again before displaying
	if (!endprogram) {
		cout << endl << "Would you like to see the menu again? Y/N: ";
		cin >> userInput;
	}

	// if user enters 'N' or 'n', the reprompt boolean is set to false and
	// program begins to terminate
	if (userInput == 'N' || userInput == 'n') {
		reprompt = false;
	}

	return reprompt;
}

void pressAnyKey() {
	cout << "Press any key to continue " << endl << endl;
	_getch();
}

string wordFormat(string& word) {
	if (word.at(0) >= 97 && word.at(0) <= 122) {
		word.at(0) = (word.at(0) - 32);
	}

	for (int i = 1; i < word.length(); i++) {
		if (word.at(i) >= 65 && word.at(i) <= 90)
		{
			word.at(i) = (word.at(i) + 32);
		}
	}

	return word;
}

string lowerCaseFormat(string word) {
	for (int i = 0; i < word.length(); i++) {
		if (word.at(i) >= 65 && word.at(i) <= 90)
		{
			word.at(i) = (word.at(i) + 32);
		}
	}

	return word;
}

void traversalMenu(BinarySearchTree& newTree) {
	int choice;

	cout << endl
		<< "---------------------------------------------------------------------\n"
		<< " Select an option from the menu below\n"
		<< " by entering the number of the choice\n"
		<< "---------------------------------------------------------------------\n"
		// 
		<< "\t1\tIn-Order Traversal\n"

		// 
		<< "\t2\tPre-Order Traversal\n"

		// 
		<< "\t3\tPost-Order Traversal\n"

		// 
		<< "\t4\tLevel-Order Traversal\n"

		<< "\t5\tReturn\n"
		<< "---------------------------------------------------------------------\n\n"
		<< "Enter your choice : \n\n";

	// switch statement that executes the case matching the user's input
	cin >> choice;
	switch (choice) {


	case 1: {
		newTree.flashCardsInOrder();
		break;
	}

	case 2: {
		newTree.flashCardsPreOrder();
		break;
	}

	case 3: {
		newTree.flashCardsPostOrder();
		break;
	}

	case 4: {
		newTree.flashCardsLevelOrder();
		break;
	}
	
	case 5: {
		break;
	}
	}
}