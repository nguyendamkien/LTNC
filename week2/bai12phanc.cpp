#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int b = trunc(sqrt(n));
    if(n == b*b) cout << "yes";
    else cout << "no";
    return 0;
}
