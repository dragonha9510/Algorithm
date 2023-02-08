#pragma once
#include "Useful.h"

int solution016(string skill, vector<string>skill_trees)
{
	int answer = 0;

	for (const auto& skills : skill_trees)
	{
		bool bCheck = false;
		vector<int> a;

		for (size_t i = 0; i < skills.size(); ++i)
		{
			for (size_t j = 0; j < skill.size(); ++j)
			{
				if (skill[j] == skills[i])
				{
					for (size_t k = 0; k < a.size(); ++k)
					{
						if (a[k] > j)
						{
							bCheck = true;
							break;
						}
					}

					if (bCheck)
						break;

					a.push_back(j);
				}
			}

			if (bCheck)
				break;
		}

		if (a.size() == 0)
			++answer;
		else if (!bCheck && a[0] == 0)
		{
			bCheck = false;

			for (size_t i = 0; i < a.size() - 1; ++i)
			{
				if (a[i + 1] - i != 1)
				{
					bCheck = true;
					break;
				}
			}

			if(!bCheck)
				++answer;
		}
	}

	return answer;
}