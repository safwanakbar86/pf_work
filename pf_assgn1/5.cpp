#include <iostream>
using namespace std;

int main()
{
	int num, count = 2;

	cout << "Enter a number: ";
	cin >> num;

    for (; num != -1;)
    {
        bool prime = true;

        for (count = 2; count <= num / 2; count++)
            if (num % count == 0)
            {
                prime = false;
                break;
            }

        if (prime == true)
            cout << num << endl;

        cout << endl << "Enter a number: ";
        cin >> num;
    }

	return 0;
}
