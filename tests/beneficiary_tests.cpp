#include "divida_tests.h"

#include <divida/beneficiary.h>

TEST_CASE("beneficiary - Construction", "[beneficiary]")
{
	auto person = std::make_shared<divida::person>(divida::tests::c_nameFrodo);
	auto weight = 0.75f;

	divida::beneficiary beneficiary(person, weight);

	CHECK(person == beneficiary.person());
	CHECK(weight == Approx(beneficiary.weight()));
}
