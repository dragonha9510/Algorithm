#pragma once
#include "Useful.h"

int solution017(vector<vector<int> > land)
{
	int max = 0;

	for (int i = 1; i < (int)land.size(); ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			max = 0;

			for (int k = 0; k < 4; ++k)
			{
				if (k == j)
					continue;
				if (max < land[i - 1][k])
					max = land[i - 1][k];
			}

			land[i][j] += max;
		}
	}

	max = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (land[land.size() - 1][i] > max)
			max = land[land.size() - 1][i];
	}

	return max;
}