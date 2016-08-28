#include "pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Divida
{
	namespace Tests
	{
		TEST_CLASS(BeneficiaryTests)
		{
		public:
			TEST_METHOD(Construction)
			{
				auto person = std::make_shared<Person>(NAME_FRODO);
				auto weight = 0.75f;

				Beneficiary beneficiary(person, weight);

				Assert::AreEqual(person, beneficiary.Person());
				Assert::AreEqual(weight, beneficiary.Weight(), FLOAT_EPSILON);
			}
		};
	}
}
