#include <iostream>

using namespace std;

int main()
{
    int iNum = 0;
    int iMax = 0;
    
    cin >> iNum >> iMax;
    
    int* pArr = new int[iNum];
    
    for(int i = 0; i < iNum; ++i)
    {
        cin >> pArr[i];
    }
    
    for(int i = 0; i < iNum; ++i)
    {
        if(pArr[i] < iMax)
            cout << pArr[i] << " ";
    }
    
    delete[] pArr;
    
    return 0;
}