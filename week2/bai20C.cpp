#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n; cin >> n;
    for(int i=1; i<=12; i++)
    {
        n = n + round(n*0.02*1000)/1000;
    }
    cout << n;
    return 0;
}
