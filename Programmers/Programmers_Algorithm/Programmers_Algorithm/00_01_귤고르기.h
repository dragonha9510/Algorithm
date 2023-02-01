#pragma once
#include "Useful.h"

void quickSort(vector<pair<int, int>>& arr, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = arr[(left + right) / 2].second;

	while (i <= j)
	{
		while (arr[i].second > pivot)
			++i;
		while (arr[j].second < pivot)
			--j;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int solution02(int k, vector<int> tangerine) 
{
	int answer = 0;
	vector<pair<int, int>> check;

	for (const auto& t : tangerine)
	{
		bool isIn = false;
		for (auto& c : check)
		{
			if (c.first == t)
			{
				isIn = true;
				++c.second;
			}
		}

		if (isIn)
			continue;

		check.push_back({ t, 1 });
	}

	quickSort(check, 0, check.size() - 1);

	for (const auto& c : check)
	{
		++answer;
		k -= c.second;

		if (k <= 0)
			break;
	}

	return answer;
}