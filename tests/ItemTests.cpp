#include "divida_tests.h"

#include <divida/Item.h>

TEST_CASE("item - Construction", "[item]")
{
	auto name = std::string("Apples");
	auto cost = 5.23f;

	divida::item item(name, cost);

	CHECK(name == item.name());
	CHECK(cost == item.cost());
}

TEST_CASE("item - ConstructionSingleBeneficiary", "[item]")
{
	auto name = std::string("Sting");
	auto cost = 497.82f;
	auto person = std::make_shared<divida::person>(divida::Tests::NAME_FRODO);
	auto beneficiary = std::make_shared<divida::beneficiary>(person);
				
	std::vector<std::shared_ptr<divida::beneficiary>> beneficiaries;
	beneficiaries.push_back(beneficiary);

	divida::item item(name, cost, beneficiaries);

	CHECK(name == item.name());
	CHECK(cost == item.cost());				
	CHECK(beneficiaries == item.beneficiaries());
}

TEST_CASE("item - ConstructionMultipleBeneficiaries", "[item]")
{
	auto name = std::string("Daggers");
	auto cost = 986631.74f;
	auto frodo = std::make_shared<divida::person>(divida::Tests::NAME_FRODO);
	auto sam = std::make_shared<divida::person>(divida::Tests::NAME_SAM);
	auto merry = std::make_shared<divida::person>(divida::Tests::NAME_MERRY);
	auto pippin = std::make_shared<divida::person>(divida::Tests::NAME_PIPPIN);

	auto beneficiaryFrodo = std::make_shared<divida::beneficiary>(frodo);
	auto beneficiarySam = std::make_shared<divida::beneficiary>(sam);
	auto beneficiaryMerry = std::make_shared<divida::beneficiary>(merry);
	auto beneficiaryPippin = std::make_shared<divida::beneficiary>(pippin);

	std::vector<std::shared_ptr<divida::beneficiary>> beneficiaries;
	beneficiaries.push_back(beneficiaryFrodo);
	beneficiaries.push_back(beneficiarySam);
	beneficiaries.push_back(beneficiaryMerry);
	beneficiaries.push_back(beneficiaryPippin);

	divida::item item(name, cost, beneficiaries);

	CHECK(name == item.name());
	CHECK(cost == item.cost());
	CHECK(beneficiaries == item.beneficiaries());
}
