#include <iostream>
using namespace std;
int main()
{
    for(int i=0; i<=23; i++)
    {
        if(i==0)  cout << "12 midnight" << endl;
        if(1<=i && i<=11 ) cout << i << " am" << endl;
        if(i==12) cout << "12 noon" << endl;
        if(i>12) cout << i-12 << " pm" << endl;
    }
    return 0;
}
