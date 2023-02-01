#pragma once
#include "Useful.h"

int solution05(int n, int k)
{
	int answer = 0;
	string num = BaseToNRadix(k, n);

	string temp = "";
	for (const auto& c : num)
	{
		if (c != '0')
		{
			temp.push_back(c);
			continue;
		}

		if (temp.size() == 0)
			continue;

		if (isPrime(StringToNum<long long>(temp)))
			++answer;

		temp.clear();
	}

	if (temp.size() != 0)
	{
		if (isPrime(StringToNum<long long>(temp)))
			++answer;
	}

	return answer;
}