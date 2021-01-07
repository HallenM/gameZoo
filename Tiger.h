#pragma once
#include "Animal.h"

class Tiger : public Animal
{
public:
	Tiger(int valueAge) {
		name = "Tiger";
		//foodType = "meat"; maxAge = 30;
		foodCount = 3;
		age = valueAge;
		satiety = 0;
	}

	virtual ~Tiger() {}

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
		if (age == 30) {
			int randValue = 1 + rand() % 2;
			if (randValue == 2) return true;
			if (randValue == 1) return false;
		}
		return false;
	}

	void grow()
	{
		if (age < 30) {
			age++;
		}
	}
};
