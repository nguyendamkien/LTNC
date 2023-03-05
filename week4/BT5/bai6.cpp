#include <iostream>

using namespace std;

int gcd(int a, int b){
    while(a * b != 0)
    {
        if(a > b) a = a % b;
        else b = b % a;
    }
    return a + b;
}

int main(){
    int a, b;
    cin >> a >> b;
    if(gcd(a,b) == 1) cout << a << ", " << b << " la so nguyen to cung nhau";
    else cout << a << ", " << b << " khong nguyen to cung nhau";
    return 0;
}
