#pragma once
#include "Useful.h"

int solution06(vector<int> elements)
{
	map<int, int> a;

	for (int i = 1; i <= (int)elements.size(); ++i)
	{
		for (int j = 0; j < (int)elements.size(); ++j)
		{
			int temp = 0;
			for (int k = j; k < j + i; ++k)
				temp += elements[k % elements.size()];
			a.insert({ temp, 0 });
		}
	}

	return (int)a.size();
}