#pragma once
#include "Useful.h"

int ToTime(string a)
{
    return ((a[0] - '0') * 600) + ((a[1] - '0') * 60) + ((a[2] - '0') * 10) + (a[3] - '0');
}

vector<int> solution012(vector<int> fees, vector<string> records)
{
    map<string, pair<bool, int>> check;
    map<string, int> result;

    for (const auto& r : records)
    {
        string tempTime;
        for (size_t i = 0; i < 5; ++i)
        {
            if (r[i] == ':')
                continue;

            tempTime.push_back(r[i]);
        }

        int curTime = ToTime(tempTime);

        string num;
        for (size_t i = 6; i < 10; ++i)
            num.push_back(r[i]);

        auto iter = check.find(num);
        if (iter == check.end())
        {
            check.insert({ num, {false, curTime} });
            continue;
        }

        if (iter->second.first == true)
        {
            iter->second.first = false;
            iter->second.second = curTime;
            continue;
        }

        iter->second.first = true;

        // 시간 책정
        auto iter2 = result.find(num);
        if (iter2 == result.end())
            result.insert({ num, (curTime - iter->second.second) });
        else
            iter2->second += (curTime - iter->second.second);
    }

    for (const auto& c : check)
    {
        if (c.second.first == true)
            continue;
        
        auto iter = result.find(c.first);
        if (iter == result.end())
            result.insert({ c.first, (1439 - c.second.second) });
        else
            iter->second += (1439 - c.second.second);
    }


    vector<int> answer;

    for (const auto& a : result)
    {
        if (a.second <= fees[0])
        {
            answer.push_back(fees[1]);
            continue;
        }

        int temp = ((a.second - fees[0]) / fees[2]);

        if (((a.second - fees[0]) % fees[2]))
            ++temp;

        answer.push_back(fees[1] + ((a.second - fees[0]) / fees[2]) * fees[3]);
    }

    return answer;
}