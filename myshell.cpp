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

int DebugStatus(int n, char **shellArgs);
int ExitStatus(int n, char *arg);

int main(int argc, char **argv){

	char *cmd;                  // Command String
	size_t cmdSize = 0;         // Size of input string
	int exitStatus = 0;         // Indicates if user entered the exit command
	int debugStatus = DebugStatus(argc, argv);  // Indicates if user called -debug option

	/* Central Program Loop */
	do{
	
	    Param *currParam = new Param();             // Param object to hold cmd
            Parse *p = new Parse();                     // Parse object to tokenize & return params	   
	    // Prompt & receive user input
	    cout << "$";
	    getline(&cmd, &cmdSize, stdin);
	    
	    // Terminates loop & program if user enters "exit"
	    exitStatus = ExitStatus(int(cmdSize), cmd);
	   
	    // Tokenizes the command into the currParam object
	    p->ParseCommand(cmd, cmdSize, currParam);

	    // Print parameters if the user called -debug
    	    if(debugStatus == 1)
	        currParam->PrintParams();
	    
	    delete currParam;
	    delete p;
    	}while(exitStatus != 1);	    
	
	cout << "******** Program Terminated *********" << endl;
	
	return 0;
}

int DebugStatus(int n, char **shellArgs){
	int status = 0;

	for(int i = 0; i < n; i++)
	{
		if(string(shellArgs[i]) == "-debug")
			status = 1;
	}

	return status;
}

int ExitStatus(int n, char *arg){
	if(arg[0] != 'e')
		return 0;
	else if(arg[1] != 'x')
		return 0;
	else if(arg[2] != 'i')
		return 0;
	else if(arg[3] != 't')
		return 0;
	else
		return 1;
}
