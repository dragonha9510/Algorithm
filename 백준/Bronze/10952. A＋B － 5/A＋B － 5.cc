#include <iostream>

using namespace std;

int main()
{
    int iA = 0, iB = 0;
    
    while(true)
    {
        cin >> iA >> iB;
        
        if(!iA && !iB)
            break;
        
        cout << iA + iB << endl;
    }
    
    return 0;
}