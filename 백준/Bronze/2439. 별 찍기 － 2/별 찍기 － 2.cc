#include <iostream>

using namespace std;

int main()
{
	int iInput = 0;

	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		for (int j = iInput; j > 0; --j)
		{
			if (i + 1 < j)
				cout << " ";
			else
				cout << "*";
		}

		if(i < iInput - 1)
			cout << "\n";
	}

	return 0;
}