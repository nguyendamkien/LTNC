#include <iostream>
using namespace std;
int uocchung(int x, int y)
{
    while(x*y!=0)
    {
        if(x>y) x=x%y;
        else y=y%x;
    }
    return x+y;
}
int main()
{
    int x, y; cin >> x >> y;
    cout << uocchung(x, y);


    return 0;
}

