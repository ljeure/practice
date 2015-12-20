// Artithmetic operations
// Written by: Luke Eure
// Date: 1/28/15

#include <iostream>

using namespace std;

int main()
{
	// addition
	cout << endl << "3 + 4 = " << 3 + 4 << endl;
	
	// subtraction
	cout << "4 - 1 = " << 4 - 1 << endl;

	// multiplication
	cout << "3 * 6 = " << 6 * 3 << endl;

	// int division
	cout << "14 / 4 = " << 15 / 4 << endl;

	// modulus
	cout << "14 % 4 = " << 15 % 4 << endl;

	// float division
	cout << "14.0 / 4.0 = " << 15.0 / 4.0 << endl;

	// order of operations
	cout << "(5 + 3) * (9 - 2) = " << (5 + 3) * (9 - 2) << endl << endl;

	// initializing integer variables
	int xInt = 11;
	int yInt = 6;

	// displaying int variable values
	cout << "x = " << xInt << endl;
	cout << "y = " << yInt << endl << endl;
	
	// addition with variables
	cout << "x + y = " << xInt + yInt << endl;

	// subtraction with variables
	cout << "x - y = " << xInt - yInt << endl;

	// multiplication with variables
	cout << "x * y = " << xInt * yInt << endl;

	// int division with variables
	cout << "x / y = " << xInt / yInt << endl;

	// modulus with variables
	cout << "x % y = " << xInt % yInt << endl << endl;

	// initializing float variables
	float aFloat = 16.0;
	float bFloat = 10.0;

	// displaying float variable values
	cout << "a = " << aFloat << endl;
	cout << "b = " << bFloat << endl << endl;

	// float division with variables
	cout << "a / b = " << aFloat / bFloat << endl;

	// order of operations with variables
	cout << "(a + b) * (x - y) = " << (aFloat + bFloat) * (xInt - yInt) << endl;


	int pause;
	cin >> pause;
	return 0;
}