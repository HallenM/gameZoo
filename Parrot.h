#pragma once
#include "Animal.h"

class Parrot : public Animal
{
public:
	Parrot(int valueAge) {
		name = "Parrot";
		//foodType = "grain"; maxAge = 5;
		foodCount = 1;
		age = valueAge;
		satiety = 0;
	}

	virtual ~Parrot() {}

	bool eatFood(string food_type)
	{
		if (food_type == "grain") {
			satiety += foodCount;
			return true;
		}
		return false;
	}

	bool death()
	{
		if (age == 5) {
			int randValue = rand() % 1;
			if (randValue == 1) return true;
			if (randValue == 0) return false;
		}
		return false;
	}

	void grow()
	{
		if (age < 5) {
			age++;
		}
	}
};
