#include <iostream>
#include <cmath>

using namespace std;

void draw(int n){
    for(int i=0; i<n; i++){
        for(int j = 1-n; j < n; j++)
        if(abs(j) <= i) cout << "*";
        else cout << " ";
        cout << endl;
        }
}

int main(){
    int n;
    cin >> n;
    draw(n);
    return 0;
}
