#include <iostream>
using namespace std;
int main()
{
    int a1, b1, c1, a2, b2, c2;

    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    int det = a1*b2 - a2*b1;
    if(det == 0)
    {
        if(b1*c2 == b2*c1) cout << "Vo so nghiem";
        else cout << "Vo nghiem";
    }
    else
    {
        int det1 = c1*b2 - c2*b1;
        int det2 = a1*c2 - a2*c1;
        cout << "x = " << det1/det << ", y = " << det2/det;
    }
    return 0;
}

