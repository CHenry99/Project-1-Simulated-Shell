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
}
