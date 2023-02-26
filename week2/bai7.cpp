#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int b = n-1;
    while(n!=-1)
    {
        if(b!=n)cout << n << " ";
        b=n;
        cin >> n;
    }
    return 0;
}
