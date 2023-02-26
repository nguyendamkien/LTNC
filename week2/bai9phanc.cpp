#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a==0 )
    {
        if(b!=0) cout << setprecision(2) << fixed << -c*1.0/b;
    }
    else
    {
        double denta = b*b-4*a*c;
        if(denta == 0) cout << setprecision(2) << fixed << (-b*1.0/(2*a));
        else
        if(denta > 0) cout << setprecision(2) << fixed << 1.0*(-b-sqrt(denta))/(2*a) << endl << 1.0*(-b+sqrt(denta))/(2*a);
        else cout << setprecision(2) << fixed << -b*1.0/(2*a) << " " << -sqrt(-denta)*1.0/(2*a) << endl << -b*1.0/(2*a) << " " << sqrt(-denta)*1.0/(2*a);

    }
    return 0;
}
