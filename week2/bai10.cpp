#include <bits/stdc++.h>

using namespace std;

struct change
{
    int a;
    double c()
    {
        return (a-32)*5.0/9;
    }
    double k()
    {
        return (a-32)*5.0/9 + 273.15;
    }
};


int main()
{
    change f[16];
    f[0].a = 0;
    for(int i=1; i<16; i++)
    {
        f[i].a = f[i-1].a + 20;
    }
    cout << "Fahrebhei" << setw(20) << "Celsius" << setw(20) << "Absolute Value" << endl;
    for(int  i = 0; i<16 ; i++)
        cout << f[i].a << setw(20) << setprecision(3) << fixed << f[i].c() << setw(20) << setprecision(3) << fixed << f[i].k() << endl;

    return 0;
}
