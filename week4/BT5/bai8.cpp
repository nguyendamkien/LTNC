#include <iostream>
#include <math.h>

using namespace std;

int rnd(double n){
    if(n - (int)n >= 0.5) return ceil(n);
    else return floor(n);

}

int main(){
    double n;
    cin >> n;
    cout << rnd(n);
    return 0;
}
