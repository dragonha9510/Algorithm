#pragma once
#include "Useful.h"

long long solution1(long long n)
{
	string answer;

	answer = NumToString<long long>(n);
	quickSort<string, int>(answer, 0, answer.size() - 1);

	return StringToNum<long long>(answer);
}