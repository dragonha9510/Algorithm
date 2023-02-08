#pragma once
#include "Useful.h"

//int Vector2d_to_Array2d(const vector<vector<int> >& v, int r, int c); //삭제하지 마세요
//char Vector_to_Array(const vector<string>& v, int arr_size); //삭제하지 마세요

int solution9999(vector<vector<int>> office, int r, int c, vector<string> move)
{
	// 0 = N, 1 = E, 2 = S, 3 = W
	int direction = 0;
	int position[2] = { r, c };

	int answer = office[r][c];
	office[r][c] = 0;

	for (const auto& m : move)
	{
		if (m != "go")
		{
			direction += m == "left" ? -1 : 1;

			if (direction < 0)
				direction = 3;
			else if (direction > 3)
				direction = 0;

			continue;
		}

		int nextPos[2] = { position[0], position[1] };

		switch (direction)
		{
		case 0:
			--nextPos[0];
			break;
		case 1:
			++nextPos[1];
			break;
		case 2:
			++nextPos[0];
			break;
		case 3:
			--nextPos[1];
			break;
		}

		if ((nextPos[0] >= (int)office.size() || nextPos[0] < 0)
			|| (nextPos[1] >= (int)office[0].size() || nextPos[1] < 0))
			continue;

		if (office[nextPos[0]][nextPos[1]] == -1)
			continue;

		answer += office[nextPos[0]][nextPos[1]];
		office[nextPos[0]][nextPos[1]] = 0;
		position[0] = nextPos[0];
		position[1] = nextPos[1];
	}

	return answer;

}

//vector<vector<int> > 를 2차원 배열로 변환하는 함수입니다.  수정하지 마세요.
int** Vector2d_to_Array2d(const vector<vector<int> >& v, int r, int c)
{
	int** arr = new int* [r];

	for (int i = 0; i < r; ++i)
	{
		arr[i] = new int[c];

		for (int j = 0; j < c; ++j)
			arr[i][j] = v[i][j];

	}

	return arr;
}

//vector<string> 을 문자열 배열로 변환하는 함수입니다.  수정하지 마세요.
char** Vector_to_Array(const vector<string>& v, int arr_size)
{
	int max_string_len = 0;

	for (auto x : v)
		max_string_len = max_string_len < (int)x.length() ? (int)x.length() : max_string_len;

	char** arr = new char* [arr_size];

	for (int i = 0; i < arr_size; ++i)
	{
		arr[i] = new char[max_string_len + 1];
		for (int j = 0; j < (int)v[i].length(); ++j)
			arr[i][j] = v[i][j];
		arr[i][v[i].length()] = 0;
	}

	return arr;
}