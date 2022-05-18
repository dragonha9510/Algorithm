#include <iostream>
#include <string>

using namespace std;

#define ZERO		0
#define STRING_O	'O'

int main()
{
	int iCaseNum	= 0;	// CaseNum
	int iScore		= 0;	// Score ( Result )
	int iCntO		= 0;	// Count 'O'
	string strOX;			// Get String

	// Get Case Number
	cin >> iCaseNum;

	for (int i = ZERO; i < iCaseNum; ++i)
	{
		cin >> strOX;	// Get String O, X
		iCntO = ZERO;	// Init iCntO
		iScore = ZERO;	// Init iScore

		for (unsigned int j = ZERO; j < strOX.length(); ++j)
		{
			if (strOX[j] == STRING_O)
			{
				++iCntO;			// Add Consecutive 'O' iCntO
				iScore += iCntO;	// Add Score iCntO
			}
			else
				iCntO = ZERO;		// Not Consecutive 'O' Clear iCntO
		}

		cout << iScore << endl;
	}

	return ZERO;
}