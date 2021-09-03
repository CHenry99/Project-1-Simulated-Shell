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
	 * not dynamically allocated - to be assigned in loop. 
	 * !Concerned about this causing errors*/
	Param* currParam;
	

	/* Central Program Loop */
	do{
	    cout << "$";
	    //Note - Newline buffer may pose an issue at some point
	    getline(cin, userInput);
	
	    //!Concern - What if ParseParam returns NULL
	    //if(userInput is not empty)
	    //currParam = parser->ParseParam(userInput);
	    
    	    /*if(-debug)
	     * currParam->printParams(); Not dynamically allocated - may not work */
	      	    
    	}while(userInput != "exit");	    
	
	
	return 0;
}
