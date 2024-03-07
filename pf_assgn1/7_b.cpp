#include <iostream>
using namespace std;

int main()
{
	int firstNum, secondNum, count, evenSum = 0, range, square = 0, oddSquare = 0, oddSum = 0;

	cout << "Enter first number: ";
	cin >> firstNum;

	cout << "Enter second number, larger than first number: ";
	cin >> secondNum;

	if (secondNum <= firstNum)
		cout << "Invalid entry! Second number should be larger than first";

	else
	{
		cout << "\nOdd numbers between " << firstNum << " and " << secondNum << ":\n";
		for (range = firstNum + 1; range < secondNum; range++)
			if (range % 2 == 1)
			{
				cout << range << ' ';
				oddSquare = range * range;
				oddSum = oddSum + oddSquare;
			}


		for (range = firstNum + 1; range < secondNum; range++)
			if (range % 2 == 0)
				evenSum = evenSum + range;
		cout << "\n\nSum of even numbers between " << firstNum << " and " << secondNum << ":\n" << evenSum << endl << endl;


		for (int sqr = 1; sqr <= 10; sqr++)
		{
			square = sqr * sqr;

			if (square > 1 && square < 10)
				cout << "Number: " << sqr << "\tSquare: " << square << endl;
		}


		cout << "\nSum of the square of odd numbers between " << firstNum << " and " << secondNum << ":\n" << oddSum << endl;


		cout << "\nUppercase letters:\n";
		for (range = firstNum + 1; range < secondNum; range++)
			if (range >= 65 && range <= 90)
				cout << static_cast<char>(range) << ' ';
	}
	

	cout << "\n";
	return 0;
}
