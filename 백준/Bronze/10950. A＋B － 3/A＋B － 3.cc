#include <iostream>

using namespace std;

int main()
{
	int iTestCase = 0;		// 테스트 진행 횟수

	int iFirst	= 0;		// 첫 번째 정수
	int iSecond = 0;		// 두 번째 정수

	cin >> iTestCase;

	for (int i = 0; i < iTestCase; ++i)
	{
		cin >> iFirst;
		cin >> iSecond;

		cout << iFirst + iSecond << endl;
	}
}