/**
 * param.hpp is the header file for the Param class
 *
 * @author Carolyn Henry
 * @date 9/2/2021
 * @info Course COP4634
 */

#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32

class Param
{
   private:
	   char *inputRedirect;
	   char *outputRedirect;
	   int background;
	   int argumentCount;
	   char *argumentVector[MAXARGS];
   public:
	   void printParams();
};

#endif
