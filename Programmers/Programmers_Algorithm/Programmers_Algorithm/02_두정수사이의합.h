#pragma once
#include "Useful.h"

long long solution2(int a, int b)
{
	int temp = a;

	a = temp > b ? b : temp;
	b = temp > b ? temp : b;

	return ((long long)a + b) * ((long long)b - a + 1) / 2;
}