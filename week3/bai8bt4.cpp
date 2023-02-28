#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
        if (a[i] <= b[i]){
            cout << "no";
            return 0;
        }
    cout << "yes";
    return 0;
}
