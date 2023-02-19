#pragma once
#include "Useful.h"

bool isGreaterOrEqual(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb >= sb + sa;
}

void merge(vector<int>& arr, int left, int mid, int right, bool (*compare)(int, int))
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right)
    {
        if ((*compare)(arr[i], arr[j]))
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int p = 0; p < (int)temp.size(); p++)
        arr[left + p] = temp[p];
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right, isGreaterOrEqual);
}

string solution020(vector<int> numbers)
{
    mergeSort(numbers, 0, numbers.size() - 1);

    string answer = "";

    for (int i = 0; i < (int)numbers.size(); i++)
        answer += to_string(numbers[i]);

    if (answer[0] == '0')
        return "0";

    return answer;
}