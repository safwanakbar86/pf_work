#include <iostream>
using namespace std;

int main()
{
	int wires = 1, num;

	cout << "Enter the number of alternating wires in your fencepost: ";
	cin >> num;

	for (wires = 1; wires <= num; wires++)
	{
		if (wires == num)
			cout << '|';

		else
			cout << "|==";
	}

	cout << '\n';

	return 0;
}
