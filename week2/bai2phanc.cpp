#include <iostream>
using namespace std;
int main()
{
    double x; int y;
    cin >> x;
    cin >> y;
    double s=1;
    for(int i=0; i<y; i++)
        s=s*x;
    cout << s;
    return 0;
}
