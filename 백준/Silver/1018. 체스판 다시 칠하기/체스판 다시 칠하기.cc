#include <iostream>
#include <string>

using namespace std;

#define MAXRESULT 400

enum WB {WHITE, BLACK, WB_END};

string CHESSCASE[WB_END][8] = 
{ 
    {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    }, 
    {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    } 
};

int CountMin(int line, int col, string str[]);

int main() 
{
    int iRes = MAXRESULT;

    int iLine = 0;
    int iCol = 0;

    cin >> iLine >> iCol;

    string* pstrChess = new string[iLine];

    for (int i = 0; i < iLine; ++i)
        cin >> pstrChess[i];

    for (int i = 0; i <= iLine - 8; ++i)
    {
        for (int j = 0; j <= iCol - 8; ++j)
        {
            int iTemp = CountMin(i, j, pstrChess);

            if (iTemp < iRes)
                iRes = iTemp;
        }
    }

    cout << iRes;

    delete[] pstrChess;
    pstrChess = nullptr;

    return 0;
}


int CountMin(int line, int col, string str[])
{
    int cnt[WB_END] = { 0 };

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (str[line + i][col + j] != CHESSCASE[WHITE][i][j])
                ++cnt[WHITE];

            if (str[line + i][col + j] != CHESSCASE[BLACK][i][j])
                ++cnt[BLACK];
        }
    }

    int iRes = cnt[WHITE] < cnt[BLACK] ? cnt[WHITE] : cnt[BLACK];

    return iRes;
}