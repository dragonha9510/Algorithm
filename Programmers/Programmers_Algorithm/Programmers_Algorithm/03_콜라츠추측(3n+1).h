#pragma once
#include "Useful.h"

int solution3(int num)
{
	if (num == 1)
		return 0;

	unsigned long long longnum = num;
	int cnt = 0;
	while (cnt <= 500)
	{
		longnum = (longnum % 2 == 0) ? (longnum / 2) : (3 * longnum + 1);
		++cnt;

		if (longnum == 1)
			return cnt;
	}

	return -1;
}