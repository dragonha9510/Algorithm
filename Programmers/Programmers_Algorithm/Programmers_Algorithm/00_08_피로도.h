#pragma once
#include "Useful.h"

int DFS(vector<vector<int>>& dungeons, int k, int idx, vector<int>& arrIdx)
{
	cout << idx << " -> ";
	if (dungeons[idx][0] > k)
		return (int)arrIdx.size() - 1;
	else if (arrIdx.size() == dungeons.size() && k > 0)
		return (int)arrIdx.size();

	int max = 0;

	for (int i = 0; i < (int)dungeons.size(); ++i)
	{
		bool checked = false;

		for (const auto& a : arrIdx)
		{
			if (a == i)
			{
				checked = true;
				break;
			}
		}

		if(checked)
			continue;

		arrIdx.push_back(i);
		int size = DFS(dungeons, k - dungeons[idx][1], i, arrIdx);
		arrIdx.pop_back();

		if (size > max)
			max = size;
	}

	return max;
}

int solution09(int k, vector<vector<int>> dungeons)
{
	vector<int> arrIdx;
	int answer = -1;

	for (int i = 0; i < (int)dungeons.size(); ++i)
	{
		arrIdx.push_back(i);
		int size = DFS(dungeons, k, i, arrIdx);
		arrIdx.pop_back();
		cout << endl;
		if (size > answer)
			answer = size;
	}

	return answer;
}