#include <iostream>

using namespace std;

int main()
{
    int A = 0;
    int B = 0;
    
    cin >> A >> B;
    
    cout << A * (B % 10) << endl;
    cout << A * ((B / 10) % 10) << endl;
    cout << A * (B / 100) << endl;
    cout << A * B << endl;
    
    return 0;
}
