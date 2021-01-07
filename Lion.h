#pragma once
#include "Animal.h"

class Lion : public Animal
{
public:
	Lion(int valueAge) {
		name = "Lion";
		//foodType = "meat"; maxAge = 20;
		foodCount = 4;
		age = valueAge;
		satiety = 0;
	}

	virtual ~Lion() {}

	bool eatFood(string food_type)
	{
		if (food_type == "meat") {
			satiety += foodCount;
			return true;
		}
		return false;
	}

	bool death()
	{
		if (age == 20) {
			int randValue = 1 + rand() % 2;
			if (randValue == 2) return true;
			if (randValue == 1) return false;
		}
		return false;
	}

	void grow()
	{
		if (age < 20) {
			age++;
		}
	}
};
