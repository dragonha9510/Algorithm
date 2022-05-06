#include <iostream>

using namespace std;

#define MAXMINUTE  60
#define MAXHOUR    24
#define HOUR       1

int main()
{
    int iHour = 0, iMinute = 0, iSetTime = 0;;
    
    cin >> iHour >> iMinute >> iSetTime;
    
    iMinute += iSetTime;
    
    if(iMinute >= MAXMINUTE)
    {
        iHour += (iMinute / MAXMINUTE);
        iMinute -= MAXMINUTE * (iMinute / MAXMINUTE);
        
        if(iHour >= MAXHOUR)
            iHour -= MAXHOUR;
    }
    
    cout << iHour << " " << iMinute;
    
    return 0;
}