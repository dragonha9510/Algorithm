#pragma once
#include "Useful.h"

string KimPosition(int position)
{
	string result = "김서방은 ";
	result += NumToString(position);
	result += "에 있다";
	return result;
}

string solution5(vector<string> seoul)
{
	string answer = "김서방은 ";
	for (size_t i = 0; i < seoul.size(); ++i)
		if (seoul[i] == "Kim")
			return KimPosition(i);

	return "없다";
}