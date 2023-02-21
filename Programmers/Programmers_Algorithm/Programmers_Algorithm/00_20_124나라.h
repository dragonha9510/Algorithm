#pragma once
#include "Useful.h"

string solution021(int n)
{
    string answer = "";

    const char arr[3] = { '1', '2', '4' };

    n -= 1;

    while (n >= 0)
    {
        answer = arr[n % 3] + answer;
        n = n / 3 - 1;
    }

    return answer;
}