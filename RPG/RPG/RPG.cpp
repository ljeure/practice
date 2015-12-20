#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>



using namespace std;

//Global objects:
//health power level xp maxhealth are stored into a vector
vector<int> stats;

//fields
enum fields {MAXHEALTH, POWER, HEALTH, LEVEL, XP};
enum mosterFields {MHEALTH, MACCURACY, MATTACK, NUM_MONSTER_FIELDS};

//define the monsters variables
int yourMonster[NUM_MONSTER_FIELDS];
string yourMonsterName;
vector<string> mTypes;	

bool youWin = false;

string weapon;
string job;


int gameover()
{
	//display the winning 
	if (youWin == true)
	{
		cout << "\n\nThe valiant Hero has killed the foul beast that\nhad kidnapped the princess! For his reward, the king granted him half of the\nkingdom, and his daughter's hand in marriage.\nThe hero was feared far and wide, and lived the rest of his days\nprotecting his vassals from all manners of evil creatuers.\n\nCONGRATULATIONS!";


	}

	cout << "\nGAME OVER\n";
	int pause;
	cin >> pause;
	exit(0);
	return 0;

}

//it seemed a lot easier and clearer to make a function to display the stats than to write it out within the game loop
int statOutput()
{
	string statNames[]  = {"Maximum health", "Power", "Health", "Level", "XP"};
	
	cout << endl << "Here are your stats:" << endl;

	for (int i = 0; i < 5; ++i)
	{
		cout << statNames[i] << ": " << stats[i] << endl;
	}
	cout << "\nAs a " << job << " your weapon of choice is a " << weapon << endl; 
	return 0;
}

//it also seemed like it'd be clearer to make a function for the movement since it takes up so much space
int move()
{
	//shuffle the monster types for level one
	random_shuffle(mTypes.begin(), mTypes.end());
	//assign the player to fight a monster
	yourMonsterName = mTypes[0];
	
	//level one monsters
	if (stats[LEVEL] == 1)
	{ 
		//possesssed rabit
		if (yourMonsterName == "Possessed Rabbit")
		{
			yourMonster[MHEALTH] = 30;
			yourMonster[MACCURACY] = 60;
			yourMonster[MATTACK] = 10;
		}

		if (yourMonsterName == "Angry Dwarf")
		{
			yourMonster[MHEALTH] = 40;
			yourMonster[MACCURACY] = 50;
			yourMonster[MATTACK] = 15;
		}

	}

	//level two monsters
	if (stats[LEVEL] == 2)
	{ 
		//fight clever rabbit, dwarf, with ten percent chance of dragon

		//dwarf
		if (yourMonsterName == "Angry Dwarf")
		{
			yourMonster[MHEALTH] = 40;
			yourMonster[MACCURACY] = 50;
			yourMonster[MATTACK] = 15;
		}

		//clever possessed rabbit
		if (yourMonsterName == "Clever Possessed Rabbit")
		{
			yourMonster[MHEALTH] = 30;
			yourMonster[MACCURACY] = 90;
			yourMonster[MATTACK] = 15;
		}

		//dragon
		if (yourMonsterName == "Dragon")
		{
			yourMonster[MHEALTH] = 60;
			yourMonster[MACCURACY] = 75;
			yourMonster[MATTACK] = 20;
		}
	}

	//level three monster
	if (stats[LEVEL] == 3)
	{ 
		//fight dragon
		yourMonster[MHEALTH] = 60;
		yourMonster[MACCURACY] = 75;
		yourMonster[MATTACK] = 20;
		yourMonsterName == "Dragon";
	}

	//You've been attacked!
	cout << endl << "You have been attacked by a " << yourMonsterName << "!";
	int aorr = 0;
	bool fight = true;
	
	while (fight == true)
	{
		//make sure they enter a correct term
		while (!(aorr == 1 || aorr == 2))
		{
			cout << "\nPlayer health: " << stats[HEALTH] << endl << yourMonsterName << " health: " << yourMonster[MHEALTH];
			cout << "\nWould you like to:\n1. Attack\n2. Run away\n";
			cin >> aorr;
		}

		//attack
		if (aorr == 1)
		{
			//your damage
			cout << "\nAttack! You deal " << stats[POWER]*stats[LEVEL] << " damage.\n";
			yourMonster[MHEALTH] -= stats[POWER]*stats[LEVEL];

			//monster damage
			cout << "\nThe " << yourMonsterName << " attacks";
			if (rand() %100 > yourMonster[MACCURACY])
			{
				cout << " but the attack missed! Lucky you...\n";
			}
			else
			{
				cout << " and deals " << yourMonster[MATTACK] << " damage.\n";
				stats[HEALTH] -= yourMonster[MATTACK];
			}

			if (stats[HEALTH] < 1 || yourMonster[MHEALTH] < 1)
				fight = false;
			aorr = 0;
		}

		//runaway
		if (aorr == 2)
			fight = false;
	}

	//post-fight information
	if (stats[HEALTH] < 1)
	{
		cout << "\nThe valiant hero has fallen in battle.\n";
		//gameover
		gameover();
	}

	if (yourMonster[MHEALTH] < 1)
	{
		cout << "\nYou have slain the foul " << yourMonsterName << ".\n+1 xp";
		stats[XP]++;
		
		//level up to 2
		if (stats[XP] == 3)
		{
			stats[LEVEL]++;
			cout << "\nCongratulations! You have leveled up to level 2!\nThe amount of damage you deal has doubled";

			//set the new monsters for level two
			mTypes.clear();
			//5/10 chance of a clever possessed rabbit
			mTypes.push_back("Clever Possessed Rabbit");
			mTypes.push_back("Clever Possessed Rabbit");
			mTypes.push_back("Clever Possessed Rabbit");
			mTypes.push_back("Clever Possessed Rabbit");
			mTypes.push_back("Clever Possessed Rabbit");

			//4/10 chance of an angry dwarf
			mTypes.push_back("Angry Dwarf");
			mTypes.push_back("Angry Dwarf");
			mTypes.push_back("Angry Dwarf");
			mTypes.push_back("Angry Dwarf");

			//1/10 chance of a dragon
			mTypes.push_back("Dragon");

		}

		//level up to 3
		if (stats[XP] == 7)
		{
			stats[LEVEL]++;
			cout << "\nCongratulations! You have leveled up to level 3!\nThe amount of damage you deal has increased 50%";
		}

		//if you defeated the dragon, you win!
		if (yourMonsterName == "Dragon")
		{
			youWin = true;
			gameover();
		}

	}

	if (aorr == 2)
	{
		cout << "\nYou make it away safely, with your pride in tatters, but all your bits\nin their right places.";
	}

	return 0;
}




int main()
{
	//set the starting monsters
	mTypes.push_back("Possessed Rabbit");
	mTypes.push_back("Angry Dwarf");

	//seed random number generator
	srand(static_cast<unsigned int>(time(0)));


	// Haven't Used this iterator yet, maybe I never will :(
	vector<int>::const_iterator iter;
	
	int uChoice = 0;

	//ask what character they want to be until they give a proper answer
	while (uChoice != 1 && uChoice != 2 && uChoice != 3 && uChoice != 4)
	{
		cout << "\nThe princess has been kidnapped by a foul Dragon!\nThe king has issued a decree that whoever slays the dragon\nwill recieve her hand in marriage\nand half the kingdom as a reward.\nCertainly a brave Hero like yourself will\nwant to take him up on this offer.\n\n";
		cout << "What was your job again?\n1. Warrior\n2. Priest\n3. Mage\n4. Peasant (Super difficult)\n\n";
		cin >> uChoice;
	}

	//set the character health and power based on their choice


	//warrior
	if (uChoice == 1)
	{
		stats.push_back(50);
		stats.push_back(10);
		weapon = "sword";
		job = "warrior";
	}
	
	//priest
	if (uChoice == 2)
	{
		stats.push_back(65);
		stats.push_back(8);
		weapon = "staff";
		job = "priest";
	}

	//mage
	if (uChoice == 3)
	{
		stats.push_back(55);
		stats.push_back(10);
		weapon = "book of spells";
		job = "mage";
	}

	//peasant  maxhealth and power
	if (uChoice == 4)
	{
		stats.push_back(40);
		stats.push_back(6);
		job = "peasant";
		weapon = "mighty pitchfork";
	}

	//give them full health, 1 level, and 0xp
	stats.push_back(stats[MAXHEALTH]);
	stats.push_back(1);
	stats.push_back(0);

	//display stats
	statOutput();
	

	bool gameOver = false;

	cout << endl << "And so the adventure begins...\nBe careful moving! There are all manners of creatures out there." << endl;

	//game loop
	while (gameOver == false)
	{
		uChoice = 0;
		//ask what they want to do next until they give a proper answer	
		while (uChoice != 1 && uChoice != 2 && uChoice != 3 && uChoice != 4)
		{
			cout << "\nValiant Hero! What would you like to do next?\n1. Move\n2. Rest\n3. View stats\n4. Quit\n";
			cin >> uChoice;
		}
		
		
			//Move
			if (uChoice == 1)
			{
				move();
			}
	
			//Rest
			if (uChoice == 2)
			{
				stats[HEALTH] = stats[MAXHEALTH];
				cout << "\nOur brave Hero takes a nap.\n...\n...\n...\n...\nYour health has been replenished.\n";
			}

			//View Stats
			if (uChoice == 3)
				statOutput();
			
			//Quit
			if (uChoice == 4)
				gameOver = true;
			

		}

	cout << "\nGAME OVER\n";


	int pause;
	cin >> pause;

	return 0;
}

