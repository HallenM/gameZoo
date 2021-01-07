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

	~Monkey() {}

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
			int randValue = 1 + rand() % 2;
			if (randValue == 2) return true;
			if (randValue == 1) return false;
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
