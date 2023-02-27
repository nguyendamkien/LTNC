#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    cin >> a[0];
    int _max = a[0];
    int _min = a[0];
    int sumchan = 0;
    if(a[0]%2==0) sumchan+=a[0];
    int demle = 0;
    if(a[0]%2!=0) demle=1;
    for(int i=1; i<n; i++)
        {
            cin >> a[i];
            if(a[i]>_max) _max = a[i];
            if(a[i]<_min) _min = a[i];
            if(a[i]%2==0) sumchan+=a[i];
            if(a[i]%2!=0) demle++;
        }
    cout << _max << endl << _min << endl << sumchan << endl << demle;

    return 0;
}
