#include <iostream>
using namespace std;

double square_root(int n);

int main()
{
	int num;
	cout << "Enter a number: ";
	cin >> num;

	cout << "Square root of " << num << ": " << square_root(num) << endl;
	return 0;
}


double square_root(int n)
{
	double guess;

	cout << "Enter your guess for square root of " << n << ": ";
	cin >> guess;

	while (guess <= 0)
	{
		cout << "Invalid entry! Enter a positive guess: ";
		cin >> guess;
	}

	double answer = guess;
	for (int count = 1; count <= 10; count++)
		answer = (static_cast<double>(answer) + (static_cast<double>(n) / static_cast<double>(answer))) / 2.0;
	
	return answer;
}
