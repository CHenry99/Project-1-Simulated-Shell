/*
 * @author Carolyn Henry
 *
 * @date 9/8/21
 */

#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../param.hpp"
#include "../parse.hpp"

TEST_CASE("Param"){
	Param * p = new Param();
	p->SetBackground(1);
	REQUIRE(p->GetBackground() == 1);
	
	p->AddArgument("hello");
	REQUIRE(p->GetArgumentCount() == 1);

	delete p;
}

TEST_CASE("Parse"){
	Parse * p = new Parse();
	char* c = ">file";

	REQUIRE(p->CheckSpecialChar(c) == 1);
	/*REQUIRE(p->CheckSpecialChar("<file") == 2);
	REQUIRED(p->CheckSpecialChar("&") == 3);
	REQUIRED(p->CheckSpecialChar("arg") == 0);

	REQUIRE(p->AddInputRedirect(">file") == true);
	REQUIRE(p->AddInputRedirect("> file") == false);

	REQUIRE(p->AddOutputRedirect("<file") == true);
	REQUIRE(p->AddOutputRedirect("< file") == false);
	*/
}
