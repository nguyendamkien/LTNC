#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int tmp;


    if(b < a){
        tmp = a; a = b; b = tmp;
    }

    if(d < c){
        tmp = c; c = d; d = tmp;
    }


    if(c < a){
        tmp = b; b = d; d = tmp;
        c = a;
    }


    a = e;


    if(b < a){
        tmp = a; a = b; b = tmp;
    }

    if(a < c){
        tmp = b; b = d; d = tmp;
        a = c;
    }

    if(d < a)
        cout << d;
    else
        cout << a;
    return 0;
}

