#include <iostream>

using namespace std;

int main()
{
	int iCaseNum = 0;
	cin >> iCaseNum;

	for (int i = 0; i < iCaseNum; ++i)
	{
		int iRepeatNum = 0;
		char chTemp[21];
		cin >> iRepeatNum >> chTemp;

		for (int j = 0; chTemp[j] != '\0'; ++j)
		{
			for (int k = 0; k < iRepeatNum; ++k)
				cout << chTemp[j];
		}

		cout << endl;
	}

	return 0;
}