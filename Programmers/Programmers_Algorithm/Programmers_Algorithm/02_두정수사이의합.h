#pragma once
#include "Useful.h"

long long solution2(int a, int b)
{
	long long temp = a;

	a = temp > b ? b : temp;
	b = temp > b ? temp : b;

	return ((long long)a + b) * (b - a + 1) / 2;
}