#pragma once
#include "Useful.h"

int getNum(int idx)
{
    int result = 0;
    int count = 0;

    while (count <= 4 - idx)
    {
        int fow = 1;

        for (int i = 0; i < count; ++i)
            fow *= 5;
        ++count;
        result += fow;
    }

    return result;
}

int solution019(string word)
{
    int answer = 0;

    char arrCharacter[5] = { 'A','E','I','O','U' };
    int idx = 0;
    for (const auto& w : word)
    {
        int num = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (w == arrCharacter[i])
            {
                num = i;
                break;
            }
        }

        answer += getNum(idx++) * num + 1;
    }

    return answer;
}