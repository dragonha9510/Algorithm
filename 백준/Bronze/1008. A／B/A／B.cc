#include <iostream>

using namespace std;

int main()
{
    double dA = 0.0;
    double dB = 0.0;
    
    cin >> dA >> dB;
    
    cout.precision(12);
    cout << fixed;
    
    cout << dA / dB;
    
    return 0;
}