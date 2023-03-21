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

void print(point *a)
{
    cout << "(" << a->x << ", " << a->y << ")" << endl;
}

int main()
{
    int m, n;
    cin >> m >> n;
    point a(m,n);
    point* b = &a;
    print(b);
    return 0;
}

