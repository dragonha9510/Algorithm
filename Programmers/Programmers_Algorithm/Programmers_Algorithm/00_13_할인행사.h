#pragma once
#include "Useful.h"

void Init(map<string, int>& checkList, vector<string>& want, vector<int>& number)
{
	for (size_t i = 0; i < want.size(); ++i)
		checkList[want[i]] = number[i];
}

int solution014(vector<string> want, vector<int> number, vector<string> discount)
{
	int answer = 0;
	map<string, int> checkList;

	for (size_t i = 0; i < want.size(); ++i)
		checkList.insert({ want[i], number[i] });

	for (size_t i = 0; i < discount.size() - 9; ++i)
	{
		for (size_t j = i; j < i + 10; ++j)
		{
			if (checkList.find(discount[j]) == checkList.end())
				continue;

			--checkList[discount[j]];
		}

		bool isAnswer = true;
		for (const auto& c : checkList)
		{
			if (c.second > 0)
			{
				isAnswer = false;
				break;
			}
		}

		if (isAnswer)
			++answer;

		Init(checkList, want, number);
	}

	return answer;
}