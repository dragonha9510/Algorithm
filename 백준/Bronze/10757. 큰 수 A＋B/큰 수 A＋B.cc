#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char A[10001] = {}, B[10001] = {};
	cin >> A >> B;

	int iUp = 0;

	int iLongLength = (int)(strlen(A) > strlen(B) ? strlen(A) : strlen(B));
	int iShortLength = (int)(strlen(A) < strlen(B) ? strlen(A) : strlen(B));

	if (iLongLength == (int)strlen(B))
	{
		char Temp[10001];

		strcpy(Temp, B);
		strcpy(B, A);
		strcpy(A, Temp);
	}

	char* strRes = new char[iLongLength + 2];
	memset(strRes, 0, iLongLength + 2);

	for (int i = iLongLength - 1; i >= 0; --i, --iShortLength)
	{
		int iTemp = A[i] - '0' + (iShortLength <= 0 ? '\0' : B[iShortLength - 1]) - '0' + iUp;

		if (iTemp < 0)
			iTemp += '0';
		
		iUp = (iTemp > 9 ? 1 : 0);

		strRes[i + 1] = (iTemp % 10) + '0';
	}

	if (iUp == 1)
		strRes[0] = '1';
	else
	{
		char* chTemp = new char [iLongLength + 1];

		memcpy(chTemp, (strRes + 1), iLongLength + 1);

		delete[] strRes;
		strRes = nullptr;

		cout << chTemp << endl;
		return 0;
	}

	cout << strRes << endl;

	delete[] strRes;
	strRes = nullptr;

	return 0;
}