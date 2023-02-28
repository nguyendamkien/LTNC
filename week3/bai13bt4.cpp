#include <iostream>

using namespace std;

bool kiemtra(int m, int a[]){
    int sum = 0;
    int sumthu = 0;
    for(int j=0; j<m; j++) {
        cin >> a[j];
        sum+=a[j];
    }
    for(int j=0; j<m; j++)
    {
        if(sumthu == sum - sumthu - a[j]){

            return true;
        }
        sumthu += a[j];
    }
    return false;
}

int main()
{
    int n; cin >> n;
    for(int i=0; i<n;i++){
        int m;
        cin >> m;
        int a[m];
        if(kiemtra(m, a)) cout << "YES";
        else cout << "NO";

    }
    return 0;
}
