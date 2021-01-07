#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(int valueAge) {
		name = "Sheep";
		//foodType = "hay"; maxAge = 15;
		foodCount = 2;
		age = valueAge;
		satiety = 0;
	}

	virtual ~Sheep() {}

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
		if (age == 15) {
			int randValue = 1 + rand() % 2;
			if (randValue == 2) return true;
			if (randValue == 1) return false;
		}
		return false;
	}

	void grow()
	{
		if (age < 15) {
			age++;
		}
	}
};
