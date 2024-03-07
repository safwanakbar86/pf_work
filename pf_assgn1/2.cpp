#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, r, count, sum = 1;

	cout << "Enter r: ";
	cin >> r;

	cout << "Enter n: ";
	cin >> n;

	cout << endl << "1 + ";

	for (count = 1; count <= n; count++)
	{
		if (count == 1)
			cout << r << " + ";

		else
		{
			cout << r << '^' << count;
			if (count < n)
				cout << " + ";
		}

		sum = sum + pow(r, count);
	}

	cout << endl << endl << "Sum of the series: " << sum << endl;

	return 0;
}
