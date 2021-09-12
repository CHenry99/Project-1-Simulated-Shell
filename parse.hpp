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
	   char* cmd;
	   Param* currParam;
	   int CheckSpecialChar(char* arg);
	   bool AddInputRedirect(char* arg);
	   bool AddOutputRedirect(char* arg);
	   void ToggleBackgroundStatus();
	   void AddRegArgument(char* arg);
   public:
	   Parse();
	   ~Parse();
	   void ParseCommand(char* cmd, size_t cmdSize, Param* currParam);
};

#endif

