#include <iostream>

using namespace std;

int main()
{
    int iMax = 0;
    int iCnt = 0;
    int iInput = 0;
    
    for(int i = 0; i < 9; ++i)
    {
        cin >>iInput;
        
        if(iMax < iInput)
        {
            iMax = iInput;
            iCnt = i + 1;
        }
    }
    
    cout << iMax << endl;
    cout << iCnt << endl;
    
    return 0;
}