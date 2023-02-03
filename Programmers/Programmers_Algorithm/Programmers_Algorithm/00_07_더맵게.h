#pragma once
#include "Useful.h"

int solution08(vector<int> scoville, int K)
{
	int answer = 0;
	while (true)
	{
		int size = scoville.size();

		if (size == 1)
		{
			if (scoville[size - 1] < K)
				return -1;

			break;
		}

		quickSort(scoville, 0, size - 1, true);
		
		if (scoville[size - 1] >= K)
			break;

		++answer;

		scoville[size - 2] = scoville[size - 1] + scoville[size - 2] * 2;
		scoville.pop_back();
	}
	return answer;
}