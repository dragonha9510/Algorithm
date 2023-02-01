#pragma once
#include "Useful.h"

int solution01(string str1, string str2)
{
	const int multi = 65536;

	vector<vector<string>> check;
	string str[2] = { str1, str2 };

	for (int i = 0; i < 2; ++i)
	{
		check.push_back(vector<string>());

		for (size_t j = 0; j < str[i].size() - 1; ++j)
		{
			string temp = "";
			for (int k = 0; k < 2; ++k)
			{
				char c = ToLowerCase(str[i][j + k]);
				if (c > 'z' || c < 'a')
					break;

				temp.push_back(c);
			}
			if (temp.size() == 2)
				check[check.size() - 1].push_back(temp);
		}
	}

	int cnt = 0;
	int size = (int)(check[0].size() + check[1].size());

	for (const auto& a : check[0])
	{
		for (size_t i = 0; i < check[1].size(); ++i)
		{
			if (a == check[1][i])
			{
				swap(check[1][i], check[1][check[1].size() - 1]);
				check[1].pop_back();
				++cnt;
				break;
			}
		}
	}

	if (size == 0)
		return multi;
	else if (cnt == 0)
		return 0;

	return (int)(((float)cnt / (size - cnt)) * multi);
}