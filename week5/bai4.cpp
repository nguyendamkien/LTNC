#include <iostream>

using namespace std;

int binarysearch(int *a, int n, int x)
{
    int i=0;
    int j = n-1;

    while(i<=j)
    {
        int m = (i+j)/2;
        if(a[m] == x) return m+1;
        else if(a[m] > x) i = m+1;
        else j = m-1;
    }
    return 0;
}

int main()
{
    int *a;
    int n; cin >> n;
    a = new int [n];
    for(int i=0; i<n; i++)
        cin >> *(a+i);
    int x; cin >> x;
    cout << binarysearch(a, n, x);
    return 0;
}
