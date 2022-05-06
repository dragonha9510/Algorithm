//시험 점수를 입력받아 
//90 ~ 100점은 A, 
//80 ~ 89점은 B, 
//70 ~ 79점은 C, 
//60 ~ 69점은 D, 
//나머지 점수는 F를 출력하는 프로그램을 작성하시오.
#include <iostream>

using namespace std;

char GetCharScore(int src)
{
    if(src < 0 && src > 100)
        return 0;
    
    char chScore;
    
    chScore = (src > 89 ? 'A' : 
               (src > 79 ? 'B' : 
                (src > 69 ? 'C' : 
                 (src > 59 ? 'D' : 'F'))));
        
    return chScore;
}

int main()
{
    int iScore = 0;
    
    cin >> iScore;
    
    cout << GetCharScore(iScore);
    
    return 0;
}

