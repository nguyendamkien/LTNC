#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int m = a+b+c;
    if((a+b>c) && (b+c>a) && (c+a>b))
    {
        if(a==b && b==c && a==c)
        {
            cout << m << endl;
            cout << "deu";
        }
        else
        if(a==b || b==c || c==a )
        {
            cout << m << endl;
            cout << "can";
        }
        else
        if(a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
        {
            cout << m << endl;
            cout << "vuong";
        }
        else
        {
            cout << m << endl;
            cout << "thuong";
        }
    }
    else cout << "Invalid";

    return 0;
}
