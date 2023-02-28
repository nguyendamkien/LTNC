#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        for(int s=j+1; s<n; s++)
        if(a[i]+a[j]+a[s] == 0) {cout << a[i] << " " << a[j] << " " << a[s];
        return 0;
        }
    cout << "no";

    return 0;
}
