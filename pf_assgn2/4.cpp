#include <iostream>
using namespace std;

int factorial(int n);
int permutations(int n, int r);
int combinations(int n, int r);
int combiPermu(int n, int r);
int menu();

int main()
{
	menu();
	return 0;
}


int factorial(int n)
{
	int count, fact = 1;

	for (count = 1; count <= n; count++)
		fact = fact * count;

	return fact;
}


int permutations(int n, int r)
{
	int nPr;
	nPr = factorial(n) / factorial(n - r);
	return nPr;
}


int combinations(int n, int r)
{
	int nCr;
	nCr = factorial(n) / (factorial(n - r) * factorial(r));
	return nCr;
}



int combiPermu(int n, int r)
{
	int nCr;
	nCr = permutations(n, r) / factorial(r);
	return nCr;
}


int menu()
{
	cout << "1. Factorial (n!)\n2. Permutations (nPr)\n3. Combinations Method 1 (nCr)\n4. Combinations Method 2 (nCr)\n5. Exit\n\n";

	int option;
	cout << "Which program would you like to run? ";
	cin >> option;


	while (option < 1 || option > 5)
	{
		cout << "There is no " << option << "th option! Try Again: ";
		cin >> option;
	}


	while (option != 5)
	{
		if (option == 4)
		{
			int num, base;
			cout << "\nEnter n: ";
			cin >> num;

			cout << "Enter r: ";
			cin >> base;

			while (num < base)
			{
				cout << "Invalid entry! n should be greater than r\n\nEnter n: ";
				cin >> num;

				cout << "Enter r: ";
				cin >> base;
			}

			cout << num << "C" << base << " = " << combiPermu(num, base) << endl;
		}

		else if (option == 3)
		{
			int num, base;
			cout << "\nEnter n: ";
			cin >> num;

			cout << "Enter r: ";
			cin >> base;

			while (num < base)
			{
				cout << "Invalid entry! n should be greater than r\n\nEnter n: ";
				cin >> num;

				cout << "Enter r: ";
				cin >> base;
			}

			cout << num << "C" << base << " = " << combinations(num, base) << endl;
		}

		else if (option == 2)
		{
			int num, base;
			cout << "\nEnter n: ";
			cin >> num;

			cout << "Enter r: ";
			cin >> base;

			while (num < base)
			{
				cout << "Invalid entry! n should be greater than r\n\nEnter n: ";
				cin >> num;

				cout << "Enter r: ";
				cin >> base;
			}

			cout << num << "P" << base << " = " << permutations(num, base) << endl;
		}

		else if (option == 1)
		{
			int num;
			cout << "\nEnter n: ";
			cin >> num;

			while (num < 0)
			{
				cout << "Invalid entry! Enter a positive value: ";
				cin >> num;
			}

			cout << num << "! = " << factorial(num) << endl;
		}

		cout << "\nWhich other program would you like to run? ";
		cin >> option;

		while (option < 1 || option > 5)
		{
			cout << "There is no " << option << "th option! Try Again: ";
			cin >> option;
		}
	}

	cout << "\nProgram exited succesfully!\n";

	return 0;
}
