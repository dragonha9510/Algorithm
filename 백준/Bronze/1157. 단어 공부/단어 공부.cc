#include <iostream>

using namespace std;

#define ALPHA 26
#define MAXSTRING 1000001
#define ISUPPERCASE(t) ('A' <= t && 'Z' >= t)
#define LOWERTOINDEX(t) (t - 'a')
#define UPPERTOINDEX(t) (t - 'A')

int main()
{
    int iArr[ALPHA] = {};
    int iIndex = 0;
    char chInput[MAXSTRING] = { '\0' };

    cin >> chInput;

    for (int i = 0; chInput[i] != '\0'; ++i)
    {
        iIndex = ISUPPERCASE(chInput[i]) ?
            UPPERTOINDEX(chInput[i]) : LOWERTOINDEX(chInput[i]);

        ++iArr[iIndex];
    }

    bool bSameCnt = false;
    int  iMax = 0;

    for (int i = 0; i < ALPHA; ++i)
    {
        if(iArr[i] == 0)
            continue;
        else if (iMax < iArr[i])
        {
            iIndex = i;
            iMax = iArr[i];
            bSameCnt = false;
        }
        else if (iMax == iArr[i])
            bSameCnt = true;
    }

    if (bSameCnt)
        cout << '?' << endl;
    else
        cout << (char)(iIndex + 'A') << endl;

    return 0;
}