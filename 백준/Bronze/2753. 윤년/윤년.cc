#include <iostream>

using namespace std;

int main()
{
    int iYear = 0;
    
    cin >> iYear;
    
    if(!(iYear % 4))
    {
        if(!(iYear % 400))
            cout << 1 << endl;
        else if(!(iYear % 100))
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    else
        cout << 0 << endl;
    
    return 0;
}