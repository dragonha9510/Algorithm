#include <iostream>

using namespace std;

#define MAXCNT 10001

int CheckSelfNum(int num)
{
	int iCheck = num;
	int iRes = num;

	while (iCheck != 0)
	{
		iRes += iCheck % 10;
		iCheck /= 10;
	}

	return iRes;
}


int main()
{
	int iNum = 0;
	bool bPrint[MAXCNT] = { false };

	for (int i = 0; i < MAXCNT; ++i)
	{
		iNum = CheckSelfNum(i);

		if(iNum < MAXCNT)
			bPrint[iNum] = true;

		if (!bPrint[i])
			cout << i << endl;
	}

	return 0;
}