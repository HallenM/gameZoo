#pragma once
#include "Animal.h"

class Cow : public Animal
{
public:
	Cow(int valueAge) {
		name = "Cow";
		//foodType = "hay"; maxAge = 25;
		foodCount = 4;
		age = valueAge;
		satiety = 0;
	}

	virtual ~Cow() {}

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
		if (age == 25) {
			int randValue = 1 + rand() % 2;
			if (randValue == 2) return true;
			if (randValue == 1) return false;
		}
		return false;
	}

	void grow()
	{
		if (age < 25) {
			age++;
		}
	}
};
