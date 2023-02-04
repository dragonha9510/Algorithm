#pragma once
#include "Useful.h"

string solution010(int n, int t, int m, int p) 
{
	string answer = "";

	int num = 0;
	int time = 1;
	bool isMyTurn = false;

	while (true)
	{
		string curNum = BaseToNRadix(n, num++);

		for (size_t i = 0; i < curNum.size(); ++i)
		{
			if (p == time++)
				isMyTurn = true;
			else
				isMyTurn = false;

			if (time > m)
				time = 1;

			if (!isMyTurn)
				continue;

			answer.push_back(curNum[i]);

			if (answer.size() == t)
				return answer;
		}
	}

	return "Error";
}