#pragma once

#include <iostream>
#include <string>

using namespace std;

#ifndef DEFINITION_H
#define DEFINITION_H

class Definition {

public:

	Definition();
	Definition(string, string);
	~Definition();

	string getWord() const;
	string getDefinition() const;
	
	void setWord(string);
	void setDefinition(string);

private:
	string wordBeingDefined;
	string wordDefinition;
};

#endif