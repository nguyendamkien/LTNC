#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        a[i] = rand() % 50;
    for(int i=0; i<n; i++) cout << a[i] << " ";
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; j<n; j++)
                if(a[i]+a[j]+a[k] == 25) cout << a[i] << " " << a[j] << " " << a[k] << endl;
    return 0;
}
