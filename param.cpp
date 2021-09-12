/**
 * This source file implements the Param class functions.
 *
 * @author Carolyn Henry
 * @date 9/2/2021
 * @info COP4634
 */

#include "param.hpp"
#include <iostream>

using namespace std;

Param::Param(){
	this->inputRedirect = NULL;
	this->outputRedirect = NULL;
	this->background = 0;
	this->argumentCount = 0;
}


/**
 * Outputs parameters
 *
 * @return returns nothing
 */
void Param::PrintParams(){
	cout << "InputRedirect: [" <<
		((inputRedirect != NULL) ? inputRedirect : "NULL") << "]" << endl <<
		"OutputRedirect: [" <<
		((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << endl <<
		"Background: [" << background << "]" << endl <<
		"ArgumentCount: [" << argumentCount << "]" << endl;

	for(int i = 0; i < argumentCount; i++)
	{
	    cout << "ArugmentVector[" << i << "]: [" <<
		    argumentVector[i] << "]" << endl;
	}
	
	
	
	
	/*if we run the example he gvae, it won't run for some  reason, so this is what I came up with - Thitari :
	cout << "InputRedirect: [";
	if(inputRedirect != NULL){
		cout << inputRedirect << "]" << endl;
	}
	else {
		cout << "NULL" << endl;
	}
	cout << "OutputRedirect: [";
	if(outputRedirect != NULL){
		cout << outputRedirect << "]" << endl;
	}
	else {
		cout << "NULL" << endl;
	}
	for(int i = 0; i < argumentCount; i++)
	{
		cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << endl;
	}
}
*/
	
	
}

/**
 * Sets Input Redirect
**/
void Param::SetInputRedirect(char *inputRedirect){
	this->inputRedirect = inputRedirect;
}

/**
 * Sets Output Redirect
**/
void Param::SetOutputRedirect(char *outputRedirect){
	this->outputRedirect = outputRedirect;
}

/**
 * Sets Background
**/
void Param::SetBackground(int background){
	this->background = background;
}

/**
 * Adds Regular Argument to Vector
**/
void Param::AddArgument(char *argument){
	this->argumentVector[this->argumentCount++] = argument;
}

