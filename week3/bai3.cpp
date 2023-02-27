#include <iostream>

using namespace std;

bool sodoiguong(int n)
{
    int b = n;
    int a = 0;
    while(n!=0){
        a*=10;
        a+=(n%10);
        n=n/10;
    }
    if(a==b) return true;
    return false;
}

void countsodoi(int a, int b)
{
    int dem = 0;
    for(int i=a; i<=b; i++)
        if(sodoiguong(i)) dem++;
    cout << dem << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        int a, b;
        cin >> a >> b;
        countsodoi(a,b);
        }
    return 0;
}
