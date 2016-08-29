#include "divida_tests.h"

#include <divida/Object.h>

TEST_CASE("object - Construction", "[object]")
{
	auto name = std::string("The object");
	divida::object object(name);

	CHECK(name == object.name());
}
