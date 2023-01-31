#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

template <typename T>
void quickSort(std::vector<T>& arr, int left, int right)
{
	int i = left;
	int j = right;
	T pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
template <typename T, typename A>
void quickSort(T& arr, int left, int right)
{
	int i = left;
	int j = right;
	A pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] > pivot)
			i++;
		while (arr[j] < pivot)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort<T, A>(arr, left, j);
	if (i < right)
		quickSort<T, A>(arr, i, right);
}

int StringToInt(const string& str, bool reverse = false)
{
	int num = 0;
	int ten = 1;

	if (reverse)
	{
		for (size_t i = 0; i < str.size(); ++i, ten *= 10)
			num += ten * (str[i] - '0');
	}
	else
	{
		for (int i = (int)str.size() - 1; i >= 0; --i, ten *= 10)
			num += ten * (str[i] - '0');
	}
	return num;
}
string IntToString(int num)
{
	string result;

	result.push_back(num % 10 + '0');
	num /= 10;

	while (num > 0)
	{
		result = (char)(num % 10 + '0') + result;
		num /= 10;
	}

	return result;
}

template<typename T>
string NumToString(T num)
{
	string result;

	result.push_back(num % 10 + '0');
	num /= 10;

	while (num > 0)
	{
		result = (char)(num % 10 + '0') + result;
		num /= 10;
	}

	return result;
}
template<typename T>
T StringToNum(string str)
{
	T num = 0;
	T ten = 1;
	for (int i = (int)str.size() - 1; i >= 0; --i, ten *= 10)
		num += ten * (str[i] - '0');

	return num;
}

int AddAllDigit(int num)
{
	int result = 0;

	while (num > 0)
	{
		result += num % 10;
		num /= 10;
	}
	return result;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}