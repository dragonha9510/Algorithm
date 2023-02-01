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

char ToLowerCase(char a)
{
	if (a <= 'Z' && a >= 'A')
		a = a - 'A' + 'a';

	return a;
}

string BaseToNRadix(int N, int n)
{
	string result;
	int Radix = 0;

	for (Radix = N; n > 0; Radix *= N)
	{
		result = (char)(((n % Radix) / (Radix / N)) + '0') + result;
		n -= n % Radix;
	}

	return result;
}

bool isPrime(long long n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (long long i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}

	return true;
}