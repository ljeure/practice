#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

	// declare variables
	string uMenuIn = "";
	string preWord = "";
	string jumWord = "";
	string wordHint = "";
	string guess = "";
	double score = 0;


	enum fields {WORD, HINT, NUM_FIELDS};

	// default words
	const int NUM_WORDS = 3;
	const int U_MAX_WORDS = 5;
	string WORDS [NUM_WORDS][NUM_FIELDS] = {
		{"happy", "What are you when you clap your hands?"},
		{"through", "Think it"},
		{"guitar", "It's gently weeping"}
	};

	// startup messsage
	cout << "\nWelcome to Word Jumble!\n";

	// user entered words
	cout << "\nYou can have a friend enter up to " << U_MAX_WORDS << " words for you to try to guess!\nS/he can also enter hints for you to use if you get stuck\n";
	cout << "\nHow many words would you like to enter?\n";
	int uNumWords = 0;
	cin >> uNumWords;

	string uWords [U_MAX_WORDS][NUM_FIELDS];

	// getline would only work if I used it once as a throwaway
	string test;
	getline (cin, test);
	
	for (int k = 0; (k < uNumWords && k < U_MAX_WORDS); k++)
	{
		

		cout << "\nEnter a word\n";
		getline (cin,uWords[k][WORD]);
		cout << "\nEnter a hint for that word\n";
		getline (cin, uWords[k][HINT]);
	}




	// seed the random number generator
	srand(static_cast<unsigned int>(time(0)));



	// start the game loop
	while (uMenuIn != "exit")
	{
		// default, enter, or quit?
		cout << "\nYour score: " << score;
		cout << "\nEnter \"default\" to play with a default word.\nType \"custom\" to play with a friend-entered word.\nType \"exit\" to quit.\n";
		cin >> uMenuIn;


		// selecting a default word
		int choice = 0;
		if (uMenuIn == "default")
		{
			choice = (rand() % NUM_WORDS);
			preWord = WORDS[choice][WORD];
			wordHint = WORDS[choice][HINT];
		}

		// selecting a custom word
		if (uMenuIn == "custom")
		{
			if (uNumWords == 0)
			{
				cout << "\nNobody entered any words!!!\n";
				int pause;
				cin >> pause;
				return 0;
			}
			choice = (rand() % NUM_WORDS);
			preWord = uWords[choice][WORD];
			wordHint = uWords[choice][HINT];
		}


		//scrambling the word
		jumWord = preWord;
		for (int j = 0; j < preWord.size(); j++)
		{
			int i1 = (rand() % preWord.size());
			int i2 = (rand() % preWord.size());
			char temp = jumWord[i1];
			jumWord[i1] = jumWord[i2];
			jumWord[i2] = temp;
		}


		// playing the game
		guess = "";
		cout << "\nYour score: " << score;
		cout << "\nGET READY TO UNJUUUUUUMMMBLLEEE!!!:\nWhat is this word?\n";
		while (guess != preWord && guess != "exit" && uMenuIn != "exit")
		{
			cout << jumWord << "\n\nA correct answer is worth 2 points.\nA wrong answer is minus 1 point.\nType \"hint\" for a hint (-.25 points)\nType \"exit\" to quit (-.5 points).\n";
			cin >> guess;

			//correct answer: add 2 points
			if (guess == preWord)
			{
				cout << "\nCOOOOOOORRECCT!!\n";
				score+=2;
			}

			// display the hint and subtract .25 from the score
			else if (guess == "hint")
			{
				cout << endl << wordHint << endl;
				score = score - .25;
			}

			//wrong answer: subtract 1
			else 
				score--;

		}

	





	}
}