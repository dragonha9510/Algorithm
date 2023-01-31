#pragma once
#include "Useful.h"

string KimPosition(int position)
{
	string result = "�輭���� ";
	result += NumToString(position);
	result += "�� �ִ�";
	return result;
}

string solution5(vector<string> seoul)
{
	string answer = "�輭���� ";
	for (size_t i = 0; i < seoul.size(); ++i)
		if (seoul[i] == "Kim")
			return KimPosition(i);

	return "����";
}