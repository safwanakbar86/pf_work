#include <iostream>
using namespace std;

bool isPrime(int x);

int main()
{
	int num, temp = 0;

	for (int count = 1; count <= 5; count++)
	{
		cout << "Enter a number: ";
		cin >> num;

		while (temp == num)
		{
			cout << "Enter a different integer: ";
			cin >> num;
		}

		(isPrime(num) == 1) ? cout << num << " is prime\n\n" : cout << num << " is not prime\n\n";
		temp = num;
	}

	return 0;
}


bool isPrime(int x)
{
	int i = 2;
	bool prime = true;

	for (i = 2; i <= x / 2; i++)
		if (x % i == 0)
		{
			prime = false;
			break;
		}

	return prime;
}
