#include <iostream>

using namespace std;

int main()
{
	int iNum = 0;		// 입력 받을 변수

	cin >> iNum;

	for (int i = 0; i < 9; ++i)
	{
		cout << iNum << " * " << (i + 1) << " = " << 
			iNum * (i + 1) << endl;
	}

	return 0;
}