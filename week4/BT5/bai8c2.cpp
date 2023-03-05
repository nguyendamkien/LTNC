#include <iostream>

using namespace std;

int rnd(double n){
    if(n - (int)n >= 0.5) return int(n) + 1;
    else return (int)n;

}

int main(){
    double n;
    cin >> n;
    cout << rnd(n);
    return 0;
}
