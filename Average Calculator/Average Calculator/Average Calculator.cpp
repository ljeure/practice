// Average Calculator
// Luke Eure
// 4/19/2015

//this seems like a really clumsy way to do it, it would have been much simpler if I could have just treated all the numbers as floats

#include <iostream>
#include <vector>

using namespace std;



int average(int terms, int num1, int num2 = 0, int num3 = 0, int num4 = 0, int num5 = 0, int num6 = 0, int num7 = 0, int num8 = 0, int num9 = 0, int num10 = 0);
float average(float terms, float num1, float num2 = 0, float num3 = 0, float num4 = 0, float num5 = 0, float num6 = 0, float num7 = 0, float num8 = 0, float num9 = 0, float num10 = 0);

int main()
{
	int uInput = 0;
	bool ints = false;

	while (uInput != 1 && uInput != 2)
	{
		cout << "\nDo you want to enter\n1. Ints\n2. Floats\n";
		cin >> uInput;
	}

	if (uInput == 1)
		ints = true;
	if (uInput == 2)
		ints = false;

	// if they entered ints
	if (ints == true)
	{
		float intIn = 0;
		while (!(intIn > 1 && intIn < 11))
		{
			cout << "\nHow many numbers would you like to take the average of?\n(Between 2 and 10)\n";
			cin >> intIn;
		}
		vector<int> numbersAverage;
		int currentTotal = 0;
		const int HOW_MANY = intIn;

		for (int i = 0; i < HOW_MANY; i++)
		{
			cout << "\nEnter number " << i + 1 << ": ";
			cin >> intIn;
			numbersAverage.push_back(intIn);
		}

		// caclulate the average. The number of arguments depends on the number of numbers they entered
		cout << "\nThe average of these numbers is ";
		if (HOW_MANY == 2)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1]);
		if (HOW_MANY == 3)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2]);
		if (HOW_MANY == 4)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3]);
		if (HOW_MANY == 5)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4]);
		if (HOW_MANY == 6)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5]);
		if (HOW_MANY == 7)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5], numbersAverage[6]);
		if (HOW_MANY == 8)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5], numbersAverage[6], numbersAverage[7]);
		if (HOW_MANY == 9)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5], numbersAverage[6], numbersAverage[7], numbersAverage[8]);		
		if (HOW_MANY == 10)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5], numbersAverage[6], numbersAverage[7], numbersAverage[8], numbersAverage[9]);

	}


	// if they entered floats
	if (ints == false)
	{
		float floatIn = 0;
		while (floatIn < 2 || floatIn > 10)
		{
			cout << "\nHow many numbers would you like to take the average of?\n(Between 2 and 10)\n";
			cin >> floatIn;
		}
		vector<float> numbersAverage;
		float currentTotal = 0;
		const float HOW_MANY = floatIn;

		for (int i = 0; i < HOW_MANY; i++)
		{
			cout << "\nEnter number " << i + 1 << ": ";
			cin >> floatIn;
			numbersAverage.push_back(floatIn);
		}

		// caclulate the average. The number of arguments depends on the number of numbers they entered
		cout << "\nThe average of these numbers is ";
		if (HOW_MANY == 2)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1]);
		if (HOW_MANY == 3)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2]);
		if (HOW_MANY == 4)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3]);
		if (HOW_MANY == 5)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4]);
		if (HOW_MANY == 6)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5]);
		if (HOW_MANY == 7)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5], numbersAverage[6]);
		if (HOW_MANY == 8)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5], numbersAverage[6], numbersAverage[7]);
		if (HOW_MANY == 9)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5], numbersAverage[6], numbersAverage[7], numbersAverage[8]);		
		if (HOW_MANY == 10)
			cout << average(HOW_MANY, numbersAverage[0], numbersAverage[1], numbersAverage[2], numbersAverage[3], numbersAverage[4], numbersAverage[5], numbersAverage[6], numbersAverage[7], numbersAverage[8], numbersAverage[9]);

		
	}

	//pause
	cin >> uInput;


	return 0;
}


// average functions
int average(int terms, int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9, int num10)
{
	return (num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10)/terms;
}

float average(float terms, float num1, float num2, float num3, float num4, float num5, float num6, float num7, float num8, float num9, float num10)
{
	return (num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10)/terms;
}