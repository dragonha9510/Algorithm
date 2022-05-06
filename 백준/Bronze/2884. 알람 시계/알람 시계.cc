#include <iostream>

using namespace std;

#define MAXMINUTE     60
#define MAXHOUR       24
#define HOUR          1

#define SANGGUNTIME   45

int main()
{
    int iHour = 0, iMinute = 0;
    
    cin >> iHour >> iMinute;
    
    if(iMinute < SANGGUNTIME)
    {
        iHour = iHour - HOUR;
        
        if(iHour < 0)
            iHour = MAXHOUR - HOUR;
        
        iMinute = MAXMINUTE - (SANGGUNTIME - iMinute);
    }
    else
        iMinute = iMinute - SANGGUNTIME;
    
    cout << iHour << " " << iMinute;
    
    return 0;
}