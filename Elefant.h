#pragma once
#include "Animal.h"

class Elefant : public Animal
{
public:
	Elefant(int valueAge) {
		name = "Elefant";
		//foodType = "hay"; maxAge = 70;
		foodCount = 18;
		age = valueAge;
		satiety = 0;
	}

	virtual ~Elefant() {}

	bool eatFood(string food_type)
	{
		if (food_type == "hay") {
			satiety += foodCount;
			return true;
		}
		return false;
	}

	bool death()
	{
		if (age == 70) {
			int randValue = rand() % 1;
			if (randValue == 1) return true;
			if (randValue == 0) return false;
		}
		return false;
	}

	void grow()
	{
		if (age < 70) {
			age++;
		}
	}
};
