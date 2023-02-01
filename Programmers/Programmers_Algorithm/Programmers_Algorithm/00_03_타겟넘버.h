#pragma once

int DFS(vector<int>& numbers, int idx, int num, int target)
{
	if (idx == numbers.size())
		return num == target ? 1 : 0;

	return DFS(numbers, idx + 1, num + numbers[idx], target) + DFS(numbers, idx + 1, num - numbers[idx], target);
}

int solution04(vector<int> numbers, int target)
{
	return DFS(numbers, 0, 0, target);
}