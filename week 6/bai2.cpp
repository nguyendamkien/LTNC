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
    cout << "(" << a.x << ", " << a.y << ")" << endl;
    cout << &a << endl;
}

void print1(point &a)
{
    cout << "(" << a.x << ", " << a.y << ")" << endl;
    cout << &a << endl;
}

int main()
{
    int m, n;
    cin >> m >> n;
    point a(m,n);
    print(a);
    cout << &a;
    return 0;
}
