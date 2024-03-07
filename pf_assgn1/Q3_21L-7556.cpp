#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long int decimal, digit = 0, count = 0, binary = 0;

	cout << "Enter a base 10 decimal number: ";
	cin >> decimal;

	for (; decimal != 0; decimal /= 2)
	{
		digit = decimal % 2;
		binary = binary + digit * pow(10, count);
		count++;
	}

	cout << "Base 2 binary: " << binary;

	return 0;
}