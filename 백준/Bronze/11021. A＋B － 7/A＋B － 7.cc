#include <iostream>

using namespace std;

int main()
{
	int iNum	= 0;
	int iFirst	= 0;
	int iSecond = 0;

	cin >> iNum;

	for (int i = 0; i < iNum; ++i)
	{
		cin >> iFirst >> iSecond;
		cout << "Case #" << i + 1 << ": " << iFirst + iSecond << "\n";
	}

	return 0;
}