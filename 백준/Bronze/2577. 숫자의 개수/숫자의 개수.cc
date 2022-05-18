#include <iostream>

using namespace std;

int main()
{
	int iArr[10] = { 0 };
	int hundMill = 100000000;

	int iMul = 0;
	int iA, iB, iC;

	cin >> iA >> iB >> iC;
	iMul = iA * iB * iC;

	while(!(iMul / hundMill))
		hundMill /= 10;

	for (int i = 0; i < 9; ++i)
	{
		iArr[iMul / hundMill]++;

		iMul %= hundMill;

		hundMill /= 10;

		if (hundMill == 0)
			break;
	}

	for (int i = 0; i < 10; ++i)
		cout << iArr[i] << endl;

	return 0;
}