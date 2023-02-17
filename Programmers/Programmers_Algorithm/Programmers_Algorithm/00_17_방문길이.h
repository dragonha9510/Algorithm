#pragma once
#include "Useful.h"

int solution018(string dirs)
{
    vector<vector<string>> check(11, vector<string>(11, ""));

    int pos[2] = { 5,5 };
    int answer = 0;

    for (const auto& d : dirs)
    {
        char checkVisit;
        int tempPos[2] = { pos[0], pos[1] };
        switch (d)
        {
        case 'U':
            --tempPos[1];
            checkVisit = 'D';
            break;
        case 'D':
            ++tempPos[1];
            checkVisit = 'U';
            break;
        case 'L':
            --tempPos[0];
            checkVisit = 'R';
            break;
        case 'R':
            ++tempPos[0];
            checkVisit = 'L';
            break;
        }

        if (tempPos[0] < 0 || tempPos[0] > 10)
            continue;
        else if (tempPos[1] < 0 || tempPos[1] > 10)
            continue;

        bool isVisit = false;
        for (const auto& c : check[pos[1]][pos[0]])
        {
            if (c == d)
            {
                isVisit = true;
                break;
            }
        }

        if (!isVisit)
        {
            for (const auto& c : check[tempPos[1]][tempPos[0]])
            {
                if (c == checkVisit)
                {
                    isVisit = true;
                    break;
                }
            }

            if (!isVisit)
            {
                check[pos[1]][pos[0]] += d;
                ++answer;
            }
        }
        pos[0] = tempPos[0];
        pos[1] = tempPos[1];
    }

    return answer;
}