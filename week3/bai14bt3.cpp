#include <iostream>

using namespace std;

void sapxep(int a[], int n){
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
    if(a[i]>a[j]){
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

int main(){
    int n; cin >> n;
    int a[n];
    int b[n+1];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int j=0; j<n+1; j++) cin >> b[j];
    sapxep(a, n);
    sapxep (b, n+1);
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i]){
            cout << b[i];
            return 0;
        }
    }
    cout << b[n];

    return 0;
}
