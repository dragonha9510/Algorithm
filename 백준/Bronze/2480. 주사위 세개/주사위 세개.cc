#include <iostream>

using namespace std;

int main()
{
    int iDice[3] = { 0 };
    int iMax = 0;
    int iCheck = 0;
    
    for(int i = 0; i < 3; ++i)
    {
        cin >> iDice[i];
        if(iMax < iDice[i])
            iMax = iDice[i];
    }
    
    for(int i = 0; i < 3; ++i)
    {
        for(int j = i + 1; j < 3; ++j)
        {
            if(iDice[i] == iDice[j])
            {
                iMax = iDice[i];
                ++iCheck;
            }
        }         
        if(iCheck == 2)
            break;
    }
    
    switch(iCheck)
    {
        case 0:
            cout << iMax * 100 << endl;
            break;
        case 1:
            cout << 1000 + (iMax * 100) << endl;
            break;
        case 2:
            cout << 10000 + (iMax * 1000) << endl;
            break;
    }
      
    return 0;
}