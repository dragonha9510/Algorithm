#pragma once
#include "Useful.h"

void quickSort(vector<int>& arr, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot)
			++i;
		while (arr[j] > pivot)
			--j;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int solution9999_1(vector<int> A, vector<int> B)
{
	quickSort(A, 0, A.size() - 1);
	quickSort(B, 0, B.size() - 1);

	int bIdx = 0;
	int answer = 0;

	for (size_t i = 0; i < A.size(); ++i)
	{
		bool isEmpty = true;
		while (bIdx < B.size())
		{
			if (A[i] >= B[bIdx++])
				continue;
			isEmpty = false;
			++answer;
			break;
		}

		if (isEmpty)
			return answer;
	}

	return answer;
}