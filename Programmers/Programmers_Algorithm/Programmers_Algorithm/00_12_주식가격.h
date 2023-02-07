#pragma once
#include "Useful.h"

vector<int> solution013(vector<int> prices)
{
	vector<int> answer(prices.size(), -1);
	vector<pair<int, int>> check(1, {0, prices[0]});

	for (size_t i = 1; i < prices.size(); ++i)
	{
		while (check.size() != 0 && prices[i] < check[check.size() - 1].second)
		{
			answer[check[check.size() - 1].first] = i - check[check.size() - 1].first;
			check.pop_back();
		}
		check.push_back({ i, prices[i] });
	}

	for (size_t i = 0; i < answer.size(); ++i)
	{
		if (answer[i] == -1)
			answer[i] = answer.size() - (i + 1);
	}

	return answer;
}