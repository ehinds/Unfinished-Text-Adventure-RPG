#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
using namespace std;

void display_stats(int level, int attack, int defense, int health, int armorRating,
	int weaponDamage, int intelligence, int perception, int agility);
void draw_heart_large(void);
void draw_heart_large_x2(void);
void draw_heart_small(void);


int main()
{
	int level = 1, attack = 1, defense = 1, health = 50, armorRating = 0, weaponDamage = 1,
		intelligence = 1, perception = 1, agility = 1, browniePoints = 0, abilityPoints = 10,
		magicDamage, magicResistance, healthTemp = 0, attackTemp = 0, defenseTemp = 0, intelTemp = 0, percepTemp = 0, agilTemp = 0;
	string CharacterName;
	char correctChoice, dummyValue;
	bool valid1 = false, valid2 = false, valid3 = false, valid4 = false, valid5 = false, valid6 = false, valid7 = false;


	cout << "Hello! Welcome to the Valentine text adventure quest!\n\nPlease enter your character's name and press enter: ";
	getline(cin, CharacterName);
	cout << "\nYour character name is " << CharacterName << "\n\nis this correct? (Enter [y/n] and press enter) \n";
	cin >> correctChoice;


	//*************************************
	//Get the character name
	//**************************************

	while (!valid1)
	{
		valid1 = true;

		while (correctChoice == 'n' || correctChoice == 'N')
		{
			cin.clear();
			cin.ignore();
			cout << "Please re-enter your character name: ";
			getline(cin, CharacterName);
			cout << "\nYour character name is " << CharacterName << "\n\nis this correct? (Enter [y/n] and press enter) \n";
			cin >> correctChoice;
		}
		if (correctChoice == 'y' || correctChoice == 'Y')
		{
			cin.clear();
			cin.ignore();
			cout << "**************************************** \n\n"
				"Great! Let's get started then, " << CharacterName << "!\n";
		}
		else if (correctChoice != 'y' || correctChoice != 'Y' || correctChoice != 'n' || correctChoice != 'N')
		{
			cin.clear();
			cin.ignore();
			cout << "Please only enter the letter Y or N: ";
			cin >> correctChoice;
			valid1 = false;
		}

	}

	cout << "So now that you have a name we need to assign some stats to your character!";
	cout << "\nFirst let me show you what your stats look like so far\n";

	//******************************************
	//show stats for first time and explain them
	//*****************************************

	display_stats(level, attack, defense, health, armorRating,
		weaponDamage, intelligence, perception, agility);

	browniePoints = (browniePoints + 1);

	cout << "As you can see above, you've already reached level 1! Woohoo!\nYou're so wonderful "
		<< CharacterName << "! Here, you deserve some brownie points for \nbeing so wonderful!\n\n You earned "
		<< browniePoints << " Brownie Point!\n (Please press the enter key to continue)\n";

	cin.ignore();
	cout << "********************************************************* \n";
	cout << "The stats work as follows:\n\nAttack: This value increases your attack damage with all melee weapons\nand is "
		"a direct counter to defense.\nFor example, if you have 5 attack and an enemy has 4 defence, you deal 1 damage.\n\n"
		"Defense: The counter to attack.\n\nHealth:The total amount of damage absorbed before dying.\n\nIntelligence: This value "
		"determines your magic damage and resistance.\n\nPerception: Your ability to perceive information swiftly"
		"as well as a direct counter to agility.\nThis allows you to deal more damage against enemies with low agility.\n\n"
		"Agility: The reflexes of a character,\nthe more swiftly you move the harder it is for opponents to keep track.\n\n";

	cout << "Please press the enter key to continue)\n\n";
	cin.ignore();
	cout << "*********************************************************\n";
	cout << "To start, I have given you 10 ability points to distribute however you like.\n\nPlease think carefully about how "
		"you would like to distribute these points.\n\n"
		"The order will be Health, Attack, Defence, Intelligence, Perception, Agility";
	cout << "\n\nHealth (Each point gives +10 health)\n\nYou have " << abilityPoints << " ability points remaining.\n"
		"\nPlease enter a number between 0 and 10 for health ";
	cin >> healthTemp;

	//***********************************************
	//Set initial stats
	//**********************************************
	while (!valid2)
	{
		valid2 = true;

		if (healthTemp < 0 == 1 || healthTemp > abilityPoints == 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
			cin >> healthTemp;
			valid2 = false;
		}

	}

	health = health + (healthTemp * 10);
	abilityPoints = abilityPoints - healthTemp;

	cout << "\nAttack: You have " << abilityPoints << " ability points remaining.\n"
		"Please enter a number between 0 and " << abilityPoints << " for Attack ";
	cin >> attackTemp;

	while (!valid3)
	{
		valid3 = true;

		if (attackTemp < 0 == 1 || attackTemp > abilityPoints == 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
			cin >> attackTemp;
			valid3 = false;
		}

	}

	attack = attack + attackTemp;
	abilityPoints = abilityPoints - attackTemp;

	cout << "\nDefense: You have " << abilityPoints << " ability points remaining.\n"
		"Please enter a number between 0 and " << abilityPoints << " for Defense ";
	cin >> defenseTemp;

	while (!valid4)
	{
		valid4 = true;

		if (defenseTemp < 0 == 1 || defenseTemp > abilityPoints == 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
			cin >> defenseTemp;
			valid4 = false;
		}

	}

	defense = defense + defenseTemp;
	abilityPoints = abilityPoints - defenseTemp;

	cout << "\nIntelligence: You have " << abilityPoints << " ability points remaining.\n"
		"Please enter a number between 0 and " << abilityPoints << " for Intelligence ";
	cin >> intelTemp;

	while (!valid5)
	{
		valid5 = true;

		if (intelTemp < 0 == 1 || intelTemp > abilityPoints == 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
			cin >> intelTemp;
			valid5 = false;
		}

	}

	intelligence = intelligence + intelTemp;
	abilityPoints = abilityPoints - intelTemp;

	cout << "\nPerception: You have " << abilityPoints << " ability points remaining.\n"
		"Please enter a number between 0 and " << abilityPoints << " for Perception ";
	cin >> percepTemp;

	while (!valid6)
	{
		valid6 = true;

		if (percepTemp < 0 == 1 || percepTemp > abilityPoints == 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
			cin >> percepTemp;
			valid6 = false;
		}

	}

	perception = perception + percepTemp;
	abilityPoints = abilityPoints - percepTemp;


	cout << "\nAgility: You have " << abilityPoints << " ability points remaining.\n"
		"Please enter a number between 0 and " << abilityPoints << " for Agility ";
	cin >> agilTemp;

	while (!valid7)
	{
		valid7 = true;

		if (agilTemp < 0 == 1 || agilTemp > abilityPoints == 1)
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
			cin >> agilTemp;
			valid7 = false;
		}
	}

	agility = agility + agilTemp;
	abilityPoints = abilityPoints - agilTemp;

	//*************************
	//display new stats.
	//*************************

	display_stats(level, attack, defense, health, armorRating,
		weaponDamage, intelligence, perception, agility);

	cout << "Are you satisfied with these stats? (y/n)";
	cin >> correctChoice;

	while (valid1)
	{
		valid1 = false;

		while (correctChoice == 'n' || correctChoice == 'N')
		{
			cin.clear();
			cin.ignore();

			//******************************
			//redo the stats
			//******************************
			attack = 1, defense = 1, health = 50, intelligence = 1, perception = 1, agility = 1, abilityPoints = 10,
				healthTemp = 0, attackTemp = 0, defenseTemp = 0, intelTemp = 0, percepTemp = 0, agilTemp = 0;
			valid1 = false, valid2 = false, valid3 = false, valid4 = false, valid5 = false, valid6 = false, valid7 = false;

			cout << "\n\nHealth (Each point gives +10 health)\n You have " << abilityPoints << " ability points remaining.\n"
				"\nPlease enter a number between 0 and 10 for health ";
			cin >> healthTemp;

			while (!valid2)
			{
				valid2 = true;

				if (healthTemp < 0 == 1 || healthTemp > abilityPoints == 1)
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
					cin >> healthTemp;
					valid2 = false;
				}

			}

			health = health + (healthTemp * 10);
			abilityPoints = abilityPoints - healthTemp;

			cout << "\nAttack: You have " << abilityPoints << " ability points remaining.\n"
				"Please enter a number between 0 and " << abilityPoints << " for Attack ";
			cin >> attackTemp;

			while (!valid3)
			{
				valid3 = true;

				if (attackTemp < 0 == 1 || attackTemp > abilityPoints == 1)
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
					cin >> attackTemp;
					valid3 = false;
				}

			}

			attack = attack + attackTemp;
			abilityPoints = abilityPoints - attackTemp;

			cout << "\nDefense: You have " << abilityPoints << " ability points remaining.\n"
				"Please enter a number between 0 and " << abilityPoints << " for Defense ";
			cin >> defenseTemp;

			while (!valid4)
			{
				valid4 = true;

				if (defenseTemp < 0 == 1 || defenseTemp > abilityPoints == 1)
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
					cin >> defenseTemp;
					valid4 = false;
				}

			}

			defense = defense + defenseTemp;
			abilityPoints = abilityPoints - defenseTemp;

			cout << "\nIntelligence: You have " << abilityPoints << " ability points remaining.\n"
				"Please enter a number between 0 and " << abilityPoints << " for Intelligence ";
			cin >> intelTemp;

			while (!valid5)
			{
				valid5 = true;

				if (intelTemp < 0 == 1 || intelTemp > abilityPoints == 1)
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
					cin >> intelTemp;
					valid5 = false;
				}

			}

			intelligence = intelligence + intelTemp;
			abilityPoints = abilityPoints - intelTemp;

			cout << "\nPerception: You have " << abilityPoints << " ability points remaining.\n"
				"Please enter a number between 0 and " << abilityPoints << " for Perception ";
			cin >> percepTemp;

			while (!valid6)
			{
				valid6 = true;

				if (percepTemp < 0 == 1 || percepTemp > abilityPoints == 1)
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
					cin >> percepTemp;
					valid6 = false;
				}

			}

			perception = perception + percepTemp;
			abilityPoints = abilityPoints - percepTemp;


			cout << "\nAgility: You have " << abilityPoints << " ability points remaining.\n"
				"Please enter a number between 0 and " << abilityPoints << " for Agility ";
			cin >> agilTemp;

			while (!valid7)
			{
				valid7 = true;

				if (agilTemp < 0 == 1 || agilTemp > abilityPoints == 1)
				{
					cin.clear();
					cin.ignore();
					cout << "Please enter a number between 0 and " << abilityPoints << " inclusive ";
					cin >> agilTemp;
					valid7 = false;
				}
			}

			agility = agility + agilTemp;
			abilityPoints = abilityPoints - agilTemp;

			//*************************
			//display new stats.
			//*************************

			display_stats(level, attack, defense, health, armorRating,
				weaponDamage, intelligence, perception, agility);
			cout << "Are you satisfied with these stats? (y/n)";
			cin >> correctChoice;
		}
		if (correctChoice == 'y' || correctChoice == 'Y')
		{
			cin.clear();
			cin.ignore();
			cout << "Great! Let's continue then, " << CharacterName << "!\n";
		}
		else if (correctChoice != 'y' || correctChoice != 'Y' || correctChoice != 'n' || correctChoice != 'N')
		{
			cin.clear();
			cin.ignore();
			cout << "Please only enter the letter Y or N: ";
			cin >> correctChoice;
			valid1 = true;
		}

	}

	return 0;

}

void display_stats(int level, int attack, int defense, int health, int armorRating,
	int weaponDamage, int intelligence, int perception, int agility)
{

	cout << "\n\nLevel = " << level << "\n";
	cout << "Health = " << health << "\n";
	cout << "Attack = " << attack << "\n";
	cout << "Defense = " << defense << "\n";
	cout << "Intelligence = " << intelligence << "\n";
	cout << "Perception = " << perception << "\n";
	cout << "Agility = " << agility << "\n\n";


}

void draw_heart_small()
{

	cout << "  ** **  ** **  ** **  ** **  ** **\n";
	cout << "  *****  *****  *****  *****  *****\n";
	cout << "   ***    ***    ***    ***    ***\n";
	cout << "    *      *      *      *      *\n\n";

}

void draw_heart_large()
{
	cout << "        ****           ****    \n";
	cout << "      ********       ********   \n";
	cout << "     ***********    ***********  \n";
	cout << "    *************  *************   \n";
	cout << "    ****************************            \n";
	cout << "     **************************    \n";
	cout << "      ************************     \n";
	cout << "       **********************  \n";
	cout << "        ********************   \n";
	cout << "          ****************   \n";
	cout << "            ************   \n";
	cout << "              ********   \n";
	cout << "                ****   \n";
	cout << "                 **   \n";
}
void draw_heart_large_x2()
{
	cout << "        ****           ****         	****           ****		\n";
	cout << "      ********       ********         ********       ********  		\n";
	cout << "     ***********    ***********      ***********    ***********  	 \n";
	cout << "    *************  *************    *************  ************* 	\n";
	cout << "    ****************************    ****************************  	\n";
	cout << "     **************************      **************************   	\n";
	cout << "      ************************        ************************   \n";
	cout << "       **********************          **********************  	\n";
	cout << "        ********************            ********************   \n";
	cout << "          ****************                ****************   \n";
	cout << "            ************                    ************  \n";
	cout << "              ********                        ********  \n";
	cout << "                ****                            ****   	\n";
	cout << "                 **                              **   	 \n";
}
