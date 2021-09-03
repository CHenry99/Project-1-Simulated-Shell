/**
 * This source file implements the Param class functions.
 *
 * @author Carolyn Henry
 * @date 9/2/2021
 * @info COP4634
 */

#include "param.hpp"
#include <iostream>
#include <string>

using namespace std;


/**
 * Outputs parameters
 *
 * @return returns nothing
 */
void Param::printParams(){
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
}

