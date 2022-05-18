#include <iostream>

using namespace std;

int main()
{
	cout << fixed;
	cout.precision(3);
	//
	int iHigherAver = 0;
	int iCaseNum	= 0;
	int iStudentNum = 0;
	float fAverage	= 0;
	float pScore[1000] = {};
	//
	cin >> iCaseNum;

	for (int i = 0; i < iCaseNum; ++i)
	{
		cin >> iStudentNum;

		for (int j = 0; j < iStudentNum; ++j)
		{
			cin >> pScore[j];

			fAverage += pScore[j];
		}

		fAverage /= (float)iStudentNum;

		for (int j = 0; j < iStudentNum; ++j)
		{
			if (fAverage < pScore[j])
				++iHigherAver;
		}

		cout << ((float)iHigherAver / (float)iStudentNum) * 100.f << "%" << endl;
		
		fAverage = 0;
		iHigherAver = 0;
		iStudentNum = 0;
	}

	return 0;
}