#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int sinhngaunhien(int n){
    srand(time(0));
    return rand() % n;
}

int main()
{
    int n; cin >> n;
    cout << sinhngaunhien(n);
    return 0;
}
