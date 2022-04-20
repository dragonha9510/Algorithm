#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int iNum	= 0;
	int iFirst	= 0;
	int iSecond = 0;

	scanf("%d", &iNum);

	for (int i = 0; i < iNum; ++i)
	{
		scanf("%d %d", &iFirst, &iSecond);
		printf("%d\n", iFirst + iSecond);
	}

	return 0;
}