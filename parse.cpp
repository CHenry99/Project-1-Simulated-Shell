/**
 * Parse.cpp implements the command line parser of the shell
 *
 * @author Carolyn Henry
 * @date 9/2/2021
 * @info Course COP4634
 */

#include <iostream>
#include "parse.hpp"

using namespace std;

Parse::Parse(){
	cout << "Parse Created" << endl;
	this->userInput = NULL;
	this->currParam = new Param();
}

Parse::~Parse(){
	
}

Param* Parse::ParseUserInput(){

	return NULL;
}

/**
 * Determines if the argument indicated file redirection or backgrounding
 * @param type is 1 for output redirect, 2 for input redirect, 0 for no redirect, 3 for background
**/
int Parse::CheckSpecialChar(char* arg){
	int type = 0;

	if(arg[0] == '>')      // Output Redirect
		type = 1;
	else if(arg[0] == '<') // Input Redirect
		type = 2;
	else if(arg[0] == '&') // Backgrounding
		type = 3;
	else
		type = 0;

	return type;
}

/**
 * SetUserInput
 * Sets the user input
**/
void Parse::SetUserInput(char* userInput){
	this->userInput = userInput;
}

/**
 * Adds the argument to the input redirect field
 * @param arg - is the argument/file name to be added
 * @return bool - false if there is a space after the < char
**/
bool Parse::AddInputRedirect(char* arg){
	/* Move the start of the string over one memory location
	 * to remove the < char */
	arg = arg + 1;
	
	//Check for spaces
	if(arg[0] == ' ')
		return false;
	
	//No space, add the redirect arg to param
	this->currParam->SetInputRedirect(arg);

	return true;
}

/**
 * Adds the argument to the output redirect field
 * @param arg - is the argument/file name to be added
 * @return bool - false if there is a space after the > char and the arg wasn't added
**/
bool Parse::AddOutputRedirect(char* arg){
	/* Move the start of the string over one memory location
	 * to remove the > char */
	arg = arg + 1;
	if(arg[0] == ' ')
		return false;

	//No space, add the redirect arg to param
	this->currParam->SetOutputRedirect(arg);

	return true;
}

/**
 * Indicates Background char was found
 * Sets appropriate field in param
**/
void Parse::ToggleBackgroundStatus(){
	this->currParam->SetBackground(1);
}

/**
 * Adds a regular type argument to the argument vector
**/
void Parse::AddRegArgument(char* arg){
	this->currParam->AddArgument(arg);
}
