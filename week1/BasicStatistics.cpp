#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int _max = a[0];
    int _min = a[0];
    int sum =a[0];
    for(int i=1; i<n; i++)
        {
            _max = max(_max, a[i]);
            _min = min(_min, a[i]);
            sum += a[i];
        }
    cout << "Mean: " << sum*1.0/n << endl << "Max: " << _max << endl << "Min: " << _min;
    return 0;
}

