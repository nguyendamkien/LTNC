#include <iostream>

using namespace std;
string bin(int n)
{
    string s = "";
    while(n != 0){
        s = (char)(n%2 + '0') + s;
        n = n / 2;
    }
    return s;
}

int pow(int x, int y){
    int s = 1;
    for(int i=0; i<y; i++)
        s = s * x;
    return s;
}

int hex(int n){
    int s = 0;
    int i = 0;
    while(n != 0){
        if(n%10 == 0) i++;
        else{
            s += pow(2, i);
            i++;
        }
        n = n / 10;
    }
    return s;
}

int main(){
    int n;
    cin >> n;
    cout << bin(n) << endl;

    int m;
    cin >> m;
    cout << hex(m);
    return 0;
}
