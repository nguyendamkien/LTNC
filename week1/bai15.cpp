#include <iostream>
using namespace std;
int main()
{
    string f0 = "a"; cout << f0 << endl;
    string f1 = "b"; cout << f1 << endl;
    string f2 = f1 + f0; cout << f2 << endl;
    string f3 = f2 + f1; cout << f3 << endl;
    string f4 = f3 + f2; cout << f4 << endl;
    string f5 = f4 + f3; cout << f5 << endl;
    string f6 = f5 + f4; cout << f6 << endl;
    string f7 = f6 + f5; cout << f7 << endl;
    string f8 = f7 + f6; cout << f8 << endl;
    string f9 = f8 + f7; cout << f9 << endl;
    string f10 = f9 + f8; cout << f10 << endl;
    return 0;
}
