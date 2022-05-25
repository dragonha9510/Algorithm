#include <iostream>

using namespace std;

#define CHARTOINT(t) (int)t - 48

int main()
{
    int iSize = 0;
    char strInput[101];
    int iRes = 0;
    
    cin >> iSize;
    cin >> strInput;
    
    for(size_t i = 0; i < iSize; ++i)
        iRes += CHARTOINT(strInput[i]);
    
    cout << iRes;
    
    return 0;
}