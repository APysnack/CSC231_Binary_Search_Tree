#include "Definition.h"
#include <string>

Definition::Definition() {
	
}

Definition::Definition(string word, string definition) {
	wordBeingDefined = word;
	wordDefinition = definition;
}

Definition::~Definition() {

}

string Definition::getWord() const {
	return wordBeingDefined;
}

string Definition::getDefinition() const {
	return wordDefinition;
}

void Definition::setWord(string word) {
	wordBeingDefined = word;
}

void Definition::setDefinition(string definition) {
	wordDefinition = definition;
}