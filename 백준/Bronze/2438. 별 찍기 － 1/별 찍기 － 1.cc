#include <iostream>

using namespace std;

int main()
{
	int iInput = 0;

	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		for (int j = 0; j < iInput; ++j)
		{
			if(i >= j)
				cout << "*";
		}
		if (i < iInput - 1)
			cout << "\n";
	}

	return 0;
}