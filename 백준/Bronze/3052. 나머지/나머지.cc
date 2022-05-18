#include <iostream>

using namespace std;

#define CONSTRAINTCNT	10
#define CONSTRAINTNUM	42
#define DEFAULT			-1

int main()
{
	bool bSameNum;

	int iRemain	= 0;
	int iResult = 0;
	int iCheckSameNum[CONSTRAINTCNT]	= { DEFAULT };

	for (int i = 0; i < CONSTRAINTCNT; ++i)
	{
		bSameNum = false;

		cin >> iRemain;

		iRemain %= CONSTRAINTNUM;

		iCheckSameNum[i] = iRemain;


		for (int j = 0; j < i; ++j)
		{
			if (iRemain == iCheckSameNum[j])
			{
				bSameNum = true;
				break;
			}
		}

		if (!bSameNum)
			++iResult;
	}

	cout << iResult << endl;

	return 0;
}