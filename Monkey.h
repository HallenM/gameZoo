#pragma once
#include "Animal.h"

class Monkey : public Animal
{
public:
	Monkey(int valueAge) {
		name = "Monkey";
		//foodType = "fruit"; maxAge = 50;
		foodCount = 3;
		age = valueAge;
		satiety = 0;
	}

	virtual ~Monkey() {}

	bool eatFood(string food_type)
	{
		if (food_type == "fruit") {
			satiety += foodCount;
			return true;
		}
		return false;
	}

	bool death()
	{
		if (age == 50) {
			int randValue = rand() % 1;
			if (randValue == 1) return true;
			if (randValue == 0) return false;
		}
		return false;
	}

	void grow()
	{
		if (age < 50) {
			age++;
		}
	}
};
