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
			int randValue = rand() % 1;
			if (randValue == 1) return true;
			if (randValue == 0) return false;
		}
		return false;
	}

	void grow()
	{
		if (age < 25) {
			age++;
		}
	}

	/*bool eatFood(string food_type)
	{
	if (food_type == "grain") {
	satiety += foodCount;
	return true;
	}
	return false;
	}*/
};