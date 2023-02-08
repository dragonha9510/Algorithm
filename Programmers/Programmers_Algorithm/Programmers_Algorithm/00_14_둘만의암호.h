#pragma once
#include "Useful.h"

string solution015(string s, string skip, int index)
{
	string answer = "";
	vector<int> alpha(26, 1);

	for (const auto& a : skip)
		alpha[a - 'a'] = 0;

	for (const auto& c : s)
	{
		int newAlpha = c - 'a';
		for (int i = 1; i <= index;)
		{
			++newAlpha;
			newAlpha %= 26;
			i += alpha[newAlpha];
		}

		answer.push_back((char)(newAlpha + 'a'));
	}
	return answer;
}