#include <iostream>

using namespace std;

bool CheckArithmetic(int num)
{
	if (num < 100)
		return true;

	int iCheck[3] = { 0 };

	iCheck[0] = num / 100;
	iCheck[1] = (num % 100) / 10;
	iCheck[2] = ((num % 100) % 10);

	int iTolerance = iCheck[0] - iCheck[1];

	if (iCheck[1] - iTolerance == iCheck[2])
		return true;

	return false;
}

int main()
{
	int iNum = 0;

	cin >> iNum;

	int iRes = 0;

	for (int i = 1; i < iNum + 1; ++i)
	{
		if (CheckArithmetic(i))
			++iRes;
	}

	cout << iRes;

	return 0;
}