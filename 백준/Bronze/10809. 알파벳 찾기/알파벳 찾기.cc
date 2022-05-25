#include <iostream>

using namespace std;

#define MAXSTRING 101
#define ALPHABET 26

int main()
{
    char strInput[MAXSTRING] = {'\0'};

    cin >> strInput;
    
    for(int i = 0; i < ALPHABET; ++i)
    {
        bool bIsIn = false;
        
        for(int j = 0; strInput[j] != '\0'; ++j)
        {
            if(strInput[j] == i + 'a')
            {
                bIsIn = true;
                cout << j << " ";
                break;
            }
        }
        
        if(!bIsIn)
            cout << "-1 ";
    }
    
    return 0;
}