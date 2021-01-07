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
			int randValue = rand() % 1;
			if (randValue == 1) return true;
			if (randValue == 0) return false;
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
