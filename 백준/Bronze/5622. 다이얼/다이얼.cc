#include <iostream>

using namespace std;

#define MAXSTRING 16
#define EIGHT 8
#define FIVE 5

int main()
{
	char chDial[EIGHT][FIVE] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
	char chInput[MAXSTRING] = { '\0' };
	int iResSec = 0;

	cin >> chInput;
	// 3 ~ 10초 2 ~ 9번

	for (int i = 0; i < MAXSTRING; ++i)
	{
		for (int j = 0; j < EIGHT; ++j)
		{
			for (int k = 0; chDial[j][k] != '\0'; ++k)
			{
				if (chInput[i] == chDial[j][k])
					iResSec += j + 3;
			}
		}
	}

	cout << iResSec;

	return 0;
}