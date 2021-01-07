#pragma once
#include "ZooManager.h"

class ZooViewContoller
{
	bool finishGame = false;
	int N;
	ZooManager manager;
public:
	ZooViewContoller() { }

	void start() {
		cout << "Hello! Welcome to Your Zoo!" << endl;
		cout << "To start, please, enter the number of cages in your Zoo:" << endl;
		cin >> N;
		manager.populateAnimals(N);
		stateZoo();
		stateMoney();
		stateWarehous();
		help();
		while (!finishGame) {
			userCommand();
		}
	}

	void stateZoo() {
		int countAnimal = 0;
		string nameAnimal = "", foodInCage = "";
		cout << "--------------------------------------------------------------------------" << endl;
		for (int i = 0; i < N; i++) {
			manager.infoAboutCage(i, nameAnimal, countAnimal, foodInCage);
			
			cout << "Enclosure " << i + 1 << ": " << nameAnimal << ".\tQuantity: " << countAnimal << ".\tEat: "
				<< manager.getFoodType(nameAnimal) << ".\tFood: " << foodInCage << ". " << endl;
		}
		cout << "--------------------------------------------------------------------------" << endl << endl;
	}

	void stateWarehous()
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Food on the warehouse:" << endl;
		cout << manager.getInfoWarehouse() << endl;
		cout << "--------------------------------------------------------------------------" << endl << endl;
	}

	void stateMoney()
	{
		cout << "\nAvailable money:\t" << manager.money << endl << endl;
	}

	void help()
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Available commands: " << endl;
		cout << "move A B to C  -  move A units of type B foods from warehouse to cage C." << endl;
		cout << "move A B from C to warehouse  -  move A units of type B foods from cage C to warehouse." << endl;
		cout << "move A B from C to cage D  -  move A units of type B foods from cage C to cage D." << endl;
		cout << "sell A B from C  -  sell A units of type B animals from cage C." << endl;
		cout << "buy A B  -  buy A units of type B foods." << endl;
		cout << "next  -  end of turn and start of a new day." << endl;
		cout << "finish  -  end of game." << endl;
		cout << "help  -  info about commands." << endl;
		cout << "--------------------------------------------------------------------------" << endl << endl;
	}

	void userCommand() {
		string command;
		cin >> command;
		if (command == "move") {
			int countFood;
			string typeFood;
			int nCage;
			cin >> countFood >> typeFood >> command;
			if (command == "to") {
				cin >> nCage;
				// move to cage
				string resp = manager.moveToCage(typeFood, countFood, nCage);
				if (resp == "success") {
					cout << "\nSuccessfull, the \"" << typeFood << "\" was moved from warehouse to " << nCage << " cage." << endl << endl;
					stateZoo();
					stateWarehous();
				}
				else {
					cout << endl << resp << endl << endl;
				}
			}
			else if (command == "from") {
				cin >> nCage >> command >> command;
				if (command == "warehouse") {
					// move to warehouse
					string resp = manager.moveToWarehouse(typeFood, countFood, nCage);
					if (resp == "success") {
						cout << "\nSuccessfull, the \"" << typeFood << "\" was moved from " << nCage << " cage to warehouse." << endl << endl;
						stateZoo();
						stateWarehous();
					}
					else {
						cout << endl << resp << endl << endl;
					}
				}
				else if (command == "cage") {
					int nSecondCage;
					cin >> nSecondCage;
					// move btw cages
					string resp = manager.moveToCage(typeFood, countFood, nCage, nSecondCage);
					if (resp == "success") {
						cout << "\nSuccessfull, the \"" << typeFood << "\" was moved from "<< nCage << " to " << nSecondCage << " cage." << endl << endl;
						stateZoo();
					}
					else {
						cout << endl << resp << endl << endl;
					}
				}
				else {
					cout << "\nWrong command, please, try again." << endl << endl;
				}
			}
			else {
				cout << "\nWrong command, please, try again." << endl << endl;
			}
		}
		else if (command == "sell") {
			int countAnimal, nCage;
			string typeAnimal;
			cin >> countAnimal >> typeAnimal >> command >> nCage;
			// sell animal
			string resp = manager.sellAnimal(typeAnimal, countAnimal, nCage);
			if (resp == "success") {
				cout << "\nSuccessfull, the \"" << typeAnimal << "\" was selled from " << nCage << " cage." << endl << endl;
				stateMoney();
				stateZoo();
			}
			else {
				cout << endl << resp << endl << endl;
			}
		}
		else if (command == "buy") {
			int countFood;
			string typeFood;
			cin >> countFood >> typeFood;
			// buy food
			string resp = manager.buyFood(typeFood, countFood);
			if (resp == "success") {
				cout << "\nSuccessfull, the \"" << countFood << " " << typeFood << "\" was bought and moved to warehouse." << endl << endl;
				stateMoney();
				stateWarehous();
			}
			else {
				cout << endl << resp << endl << endl;
			}
		}
		else if (command == "next") {
			//func end turn
			string resp = manager.feedingAndBreeding();
			cout << endl << resp << endl << endl;
			stateZoo();
		}
		else if (command == "finish") {
			finishGame = true;
		}
		else if (command == "help") {
			help();
		}
		else {
			cout << "\nWrong command, please, try again." << endl << endl;
		}
	}
};
