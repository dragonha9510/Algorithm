#pragma once
#include "Useful.h"

int solution4(int n)
{
	for (int i = 2; i < n; ++i)
		if (n % i == 1)
			return i;

	return 0;
}