#include <iostream>
using namespace std;
int main()
{
    bool b;
    int x, y, z; cin >> x >> y >> z;
    if((x <=y && y<=z) || (x>=y && y>=z)) b=true;
        else b=false;
    cout << b;
    return 0;
}
