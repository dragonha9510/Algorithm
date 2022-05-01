//첫째 줄에 A+B, 둘째 줄에 A-B, 셋째 줄에 A*B, 넷째 줄에 A/B, 다섯째 줄에 A%B를 출력한다.

#include <iostream>

using namespace std;

int main()
{
    int iA = 0;
    int iB = 0;
    
    cin >> iA >> iB;
    
    cout << iA + iB << endl;
    cout << iA - iB << endl;
    cout << iA * iB << endl;
    cout << int(iA / iB) << endl;
    cout << iA % iB << endl;
    
    return 0;
}