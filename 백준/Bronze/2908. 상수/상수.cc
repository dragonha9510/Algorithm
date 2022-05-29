#include <iostream>

using namespace std;

#define TWO 2
#define THREE 3
#define FOUR 4

int main()
{
	int iRes = -1;
	char chNum[TWO][FOUR] = { {'\0'}, {'\0'} };
	char chRes[FOUR] = { '\0' };

	cin >> chNum[0] >> chNum[1];

	for (int i = TWO; i >= 0; --i)
	{
		iRes = chNum[0][i] == chNum[1][i] ? -1 : (chNum[0][i] < chNum[1][i] ? 1 : 0);

		if (iRes != -1)
			break;
	}

	int iIndex = TWO;
	for (int i = 0; i < THREE; ++i)
		chRes[i] = chNum[iRes][iIndex--];

	cout << chRes << endl;

	return 0;
}