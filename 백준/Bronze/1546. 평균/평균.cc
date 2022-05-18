#include <iostream>

using namespace std;

#define ZERO				0
#define _ERROR				-1
#define D_MAXSCORE			100.0
#define FORATOB(a, b)		int i = a; i < b; ++i
#define NULLCHECKERROR(t)	if(t == NULL) return _ERROR;
#define DELETENULL(t)		if(t != NULL) delete t; t = NULL;

int main()
{
	int iSubjectNum = 0;

	cin >> iSubjectNum;

	double* dScore = new double[iSubjectNum];

	NULLCHECKERROR(dScore);

	double dHighScore	= ZERO;
	double dAverage		= ZERO;

	for (FORATOB(ZERO, iSubjectNum))
	{
		cin >> dScore[i];

		dHighScore = (dHighScore < dScore[i] ? dScore[i] : dHighScore);
	}

	for (FORATOB(ZERO, iSubjectNum))
	{
		dScore[i] = dScore[i] / dHighScore * D_MAXSCORE;

		dAverage += (dScore[i] / (double)iSubjectNum);
	}

	cout << dAverage;

	DELETENULL(dScore);

	return ZERO;
}