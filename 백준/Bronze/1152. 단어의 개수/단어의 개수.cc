#include <iostream>

using namespace std;

#define MAXSTRING 1000001

int main()
{
    char chInput[MAXSTRING] = { '\0' };
    int iCnt = 0;

    cin.getline(chInput, MAXSTRING);

    for (int i = 0; chInput[i] != '\0'; ++i)
    {
        if (i == 0 && chInput[i] == ' ')
            continue;
        else if (chInput[i] == ' ')
            ++iCnt;
        else if ((i + 1) <= MAXSTRING)
        {
            if (chInput[i + 1] == '\0')
                ++iCnt;
        }
    }

    cout << iCnt << endl;

    return 0;
}