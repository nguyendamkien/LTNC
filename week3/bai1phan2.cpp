#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    double tb = sum*1.0/n;
    double phuongsai = 0;
    for(int i=0; i<n; i++)
    {
        phuongsai+=(a[i]-tb)*(a[i]-tb)/n;
    }
    cout << tb << endl << phuongsai;
    return 0;
}
