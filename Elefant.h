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

	~Elefant() {}

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
			int randValue = 1 + rand() % 2;
			if (randValue == 2) return true;
			if (randValue == 1) return false;
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
