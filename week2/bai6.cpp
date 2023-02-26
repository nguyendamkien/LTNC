#include <iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int k=i+1; k<=i+n; k++)
            if(k>n) cout << k-n << " ";
            else cout << k << " ";
        cout << endl;
    }
    return 0;
}
