#include <iostream>
#define log(message) std::cout << message
using namespace std;




class Character {

public:
	static const enum characterTypes
	{
		soldier
	};

private:
	bool typeSet = false;
	characterTypes m_characterType;
	short m_health;
	short m_strength;
	const char* m_name = "Greg";

public:

	Character(characterTypes characterType) {
		if (typeSet) {
			log("Already initialsed\n");
			return;
		}

		switch (characterType)
		{
		case characterTypes::soldier:
			m_characterType = characterType;
			m_health = 50;
			m_strength = 5;

			typeSet = true;
			cout << "Successfully made a soldier!\n";
			break;
		default:
			break;
		}
	}




public:
	
	void setName(const char* name) {
		m_name = name;
		log("Name successfully set to " << name << "!\n");
	}
	
	short getHealth() {
		return m_health;
	}

	short getStrength() {
		return m_strength;
	}

	const char* getName() {
		return m_name;
	}

	bool attack1(Character opponent) {
		srand(time(0));
		bool hit = (rand() % 100 + 1) > 25;
		
		if (hit) {
			opponent.hit(m_strength * 1.2);

		}
	}

	bool attack2(Character opponent){
		srand(time(0));
		bool hit = (rand() % 100 + 1) > 70;

		if (hit) {
			opponent.hit(m_strength * 1.75);
		}
		else {
			log("You missed!");
		}

	}

	void hit(short damage) {

		m_health -= damage;

	}


};


short getOption() {
	short option;
	bool validOption = false;
	do {
		log(">> ");
		cin >> option;
		validOption = option == 1 || option == 2 || option == 3;
	} while (!validOption);
	
	return option;
}

int main() {
	
	while (true) {
		log("\033[2J\033[1;1H");
		log("1) Start\n2) Exit\n");

		short option;
		bool validOption = false;
		do {
			log(">> ");
			cin >> option;
			validOption = option == 1 || option == 2;
		} while (!validOption);

		if (option == 2)
			break;
		
		while (true) {

			log("\033[2J\033[1;1H");
			log("1) Create Character\n2) View Characters\n3) Back\n");
			option = getOption();
			if (option == 3)
				break;

			while (true) {
				log("\033[2J\033[1;1H");
				log("1) Soldier\n2) Back\n");
				option = getOption();
				if (option == 2)
					break;
				
				if (option == 1) {
					Character character(Character::characterTypes::soldier);
					cout << character.getName() << endl;
					cout << character.getHealth() << endl;
					cout << character.getStrength() << endl;
				}
				system("pause");

			}
		}
	}
	
	
	return 0;
}