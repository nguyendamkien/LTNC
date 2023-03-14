#include <iostream>

using namespace std;

int count_even(int *a, int n)
{
    int s = 0;
    for(int i=0; i<n; i++)
        if(*(a+i) % 2 == 0) s++;
    return s;
}

int main()
{
    int *a;
    int n; cin >> n;
    a = new int [n];
    for(int i=0; i<n; i++)
        cin >> *(a+i);
    int m; cin >> m;
    cout << count_even(a, m);
    return 0;
}
