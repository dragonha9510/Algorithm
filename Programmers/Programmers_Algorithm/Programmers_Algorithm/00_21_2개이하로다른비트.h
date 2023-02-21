#pragma once
#include "Useful.h"

vector<long long> solution022(vector<long long> numbers)
{
    vector<long long> answer;

    for (const auto& n : numbers)
    {
        string nums = '0' + BaseToNRadix(2, n);
        
        for (int i = (int)nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] == '0')
            {
                nums[i] = '1';

                if (i != nums.size() - 1)
                    nums[i + 1] = '0';

                break;
            }
        }

        answer.push_back(stringBinToBase(nums));
    }

    return answer;
}