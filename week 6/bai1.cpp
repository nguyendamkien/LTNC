#include <iostream>

using namespace std;

struct point
{
    int x;
    int y;
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

};

void print(point a)
{
    cout << "(" << a.x << ", " << a.y << ")";
}

int main()
{
    int m, n;
    cin >> m >> n;
    point a(m,n);
    print(a);
    return 0;
}
