#include <bits/stdc++.h>
using namespace std;
bool prime(int n)
{
   for(int i=2; i<n; i++)
   if(n%i==0) return false;
   return true;
}
bool chinhphuong(int n)
{
    int b = trunc(sqrt(n));
    if(n == b*b) return true;
    else return false;
}
bool hoanhao(int n)
{
    int s = 1;
    for(int i=2; i<n; i++)
    {
        if(n%i==0) s+=i;
    }
    if(s==n) return true;
    else return false;
}
int main()
{
    int n; cin >> n;
    for(int i=2; i<=n; i++) if(prime(i)) cout << i << " ";
    cout << endl;
    for(int i=2; i<=n; i++) if(hoanhao(i)) cout << i << " ";
    cout << endl;
    for(int i=2; i<=n; i++) if(chinhphuong(i)) cout << i << " ";
    cout << endl;

    return 0;
}
