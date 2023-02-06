#pragma once
#include "Useful.h"

vector<string> solution011(vector<string> record)
{
	map<string, string> check;
	vector<pair<string, int>> recordCheck;

	for (const auto& r : record)
	{
		int idx = 6;
		if (r[0] == 'C')
			idx = 7;

		// uid Check
		string uid;
		for (size_t i = idx; i < r.size(); ++i)
		{
			if (r[i] == ' ')
			{
				idx = i + 1;
				break;
			}
			uid.push_back(r[i]);
		}

		string nickName;

		// NickName Check
		if (r[0] != 'L')
		{
			for (size_t i = idx; i < r.size(); ++i)
				nickName.push_back(r[i]);

			auto iter = check.find(uid);
			if (iter == check.end())
				check.insert({ uid, nickName });
			else
				check[uid] = nickName;
		}

		if (r[0] == 'C')
			continue;

		// E, L
		recordCheck.push_back({ uid, (r[0] == 'L') ? 1 : 0 });
	}

	vector<string> answer;

	for (const auto& r : recordCheck)
	{
		string result = check[r.first];
		if (r.second == 0)
			result += "님이 들어왔습니다.";
		else
			result += "님이 나갔습니다.";

		answer.push_back(result);
	}

	return answer;
}