/**
 * Parse.cpp implements the command line parser of the shell
 *
 * @author Carolyn Henry
 * @date 9/2/2021
 * @info Course COP4634
 */

#include <iostream>
#include <cstring>
#include "parse.hpp"

using namespace std;

Parse::Parse(){
	this->cmd = NULL;
	this->currParam = NULL;
}

Parse::~Parse(){
		
}

/*
 * Tokenizes the user command, evaluates for special characters, places arguments in Param object
*/
bool Parse::ParseCommand(char *cmd, size_t cmdSize, Param* currParam){
	this->cmd = cmd;
	this->currParam = currParam;
	int argType; 			// Will indicate what type of argument to add
	bool errorStatus = true;  		// Indicates error for input/output redirect

	// Tokenization Loop
	char *token = strtok(cmd, " \n\t");
	while(token != NULL)
	{
		cout << "TOKEN: " << token << endl;
		// Check if the argument is special
		argType = CheckSpecialChar(token);

		// Arguments are added via class functions based on type of argument
		// @param error status monitors if there is an error
		if(argType == 1)
			errorStatus = this->AddOutputRedirect(token);
			else if(argType == 2)
				errorStatus = this->AddInputRedirect(token);
				else if(argType == 3)
					this->ToggleBackgroundStatus();
					else
						this->AddRegArgument(token);

		// Check error status - stops accepting input if there is an error		
		if(errorStatus == false)
			return false;

		token = strtok(NULL, " \n\t");
	}                  
	
	return true;
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
 * Adds the argument to the input redirect field
 * @param arg - is the argument/file name to be added
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
