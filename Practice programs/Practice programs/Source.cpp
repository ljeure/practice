#include <iostream>

using namespace::std;


 int asdf()
 {
	int track, count;

	track = 0;
	do
	{
		// get number to count to
		cout << endl << "What should I count to? " << endl;
		cin >> track;
		cout << endl;

		count = 0;
		while (count <= track)
		{
			cout << count << endl;
			count += 1;
		}
	} while (track != 0);
	 
	 
	 
	 
	 
	int score;
	cout << endl << "Enter a score " << endl;
	cin >> score;




	switch (score)
	{
	case 250: cout << "you scored more than 250!" << endl;
	case 500: cout << "you scored more than 500!" << endl;
	case 600: cout << "you scored more than 600!" << endl;
	case 752: cout << "you scored more than 752!" << endl;
	}

	int pause;
	cin >> pause;

	return 0;
 }