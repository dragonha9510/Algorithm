#pragma once
#include "Useful.h"

vector<int> solution07(string msg)
{
	vector<string> check(26, "");
	vector<int> answer;

	for (int i = 0; i < 26; ++i)
		check[i].push_back((char)(i + 'A'));

	for (size_t i = 0; i < msg.size(); ++i)
	{
		for (int j = (int)check.size() - 1; j >= 0; --j)
		{
			bool isIn = true;

			for (size_t k = 0; k < check[j].size(); ++k)
			{
				if (check[j][k] == msg[i + k])
					continue;

				isIn = false;
				break;
			}

			if (!isIn)
				continue;

			answer.push_back(j + 1);
			check.push_back("");

			for (size_t k = 0; k <= check[j].size(); ++k)
				check[check.size() - 1].push_back(msg[i + k]);

			i += check[j].size() - 1;

			break;
		}
	}

	return answer;
}