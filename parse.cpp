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
}

Parse::~Parse(){
	
}

Param* Parse::ParseUserInput(char* userInput, int n){

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
