#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    int dem[10];
    for(int i=0; i<10; i++) dem[i]=0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        dem[a[i]]++;
    }
    for(int i=0; i<10; i++)
        cout << i << " la " << dem[i] << endl;
    return 0;
}
