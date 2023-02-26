#include <iostream>

using namespace std;

int main()
{
    long long thunhap; cin >> thunhap;
    long long baohiem = thunhap*9.0/100;
    long long thunhapchiuthue = thunhap - baohiem;
    long long thue;
    if(thunhapchiuthue <= 1000000) {
            thue =0;
    }
    else if(thunhapchiuthue>1000000 && thunhapchiuthue<=1500000){
        thue = (thunhapchiuthue-1000000)*10.0/100;
    }
    else if(thunhapchiuthue>1500000 && thunhapchiuthue<=2000000){
        thue = 500000*10.0/100 + (thunhapchiuthue-1500000)*15.0/100;
    }
    else if(thunhapchiuthue>2000000){
        thue = 500000*10.0/100 + 500000*15.0/100 + (thunhapchiuthue-2000000)*20/100;
    }

    cout << thue << endl;
    cout << thunhap - baohiem - thue;
}
