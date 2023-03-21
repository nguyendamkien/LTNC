#include <iostream>

using namespace std;

struct point
{
    double x;
    double y;
    point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

};

point mid_point(const point &a,const point &b)
    {
        point midpoint;
        midpoint.x = (a.x + b.x) / 2;
        midpoint.y = (a.y + b.y) / 2;
        return midpoint;
    }

int main()
{
    point a(3,4);
    point b(5,6);
    point c = mid_point(a, b);
    cout << c.x << " " << c.y;

    return 0;
}

