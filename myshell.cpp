/**
 * Runs the main program
 *
 * @author Carolyn Henry
 * @date 9/2/2021
 * @info Course COP4634
 */

#include <iostream>
#include <string>
#include "param.hpp"
#include "parse.hpp"

using namespace std;
int main(){
	string userInput = "";	
	Parse* parser = new Parse();

	/* @param currParam
	 * not dynamically allocated - to be assigned in loop. */
	Param* currParam;
	

	/* Central Program Loop */
	do{
	    cout << "$";
	    //Note - Newline buffer may pose an issue at some point
	    getline(cin, userInput);
	

    	}while(userInput != "");	    
	
	
	return 0;
}
