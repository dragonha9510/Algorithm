#include <iostream>

using namespace std;

#define CROALPHA 8
#define MAXCRO 4
#define BUFFERMAX 256

int main()
{
	char	chCro[CROALPHA][MAXCRO] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	int		iCroLen[CROALPHA] = { 2,2,3,2,2,2,2,2 };

	char chInput[BUFFERMAX] = {'\0'};

	cin >> chInput;

	int iRes = 0;

	for (int i = 0; chInput[i] != '\0'; ++i)
	{
		bool bIsCro = true;

		for (int j = 0; j < CROALPHA; ++j)
		{
			bIsCro = true;

			for (int k = 0; k < iCroLen[j]; ++k)
			{
				if (chInput[i + k] != chCro[j][k])
				{
					bIsCro = false; 
					break;
				}
			}

			if (bIsCro)
			{
				++iRes; 
				i += iCroLen[j] - 1; 
				break;
			}
		}

		if (!bIsCro)
			++iRes;
	}

	cout << iRes;

	return 0;
}