/**
 * This defines functionality of parser
 * Recieves string (or char array?) from Command Line - Returns Param?
 *
 * @author Carolyn Henry
 * @date 9/2/21
 * @info Course COP4634
 */

#ifndef PARSE_HPP
#define PARSE_HPP

#include "param.hpp"

class Parse{
   private:
	   Param* currParam;
	   std::string userInput; //char* ?
   public:
	   Parse();
	   ~Parse();
	   void SetUserInput(std::string userInput);
	   Param* GetCurrParam();
};

#endif

