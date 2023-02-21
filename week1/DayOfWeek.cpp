#include <iostream>
using namespace std;
int main()
{
    int  day, month, year;
    cin >> day >> month >> year;
    int a = (14 - month)/12;
    int y = year - a;
    int m = month +12*a -2;
    int DayOfWeek = (day + y +y/4 - y/100 + y/400 +(31*m)/12)%7;
    switch(DayOfWeek)
    {

    case 0:
        cout << "Sunday";
        break;
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout <<  "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;

    }

    return 0;
}
