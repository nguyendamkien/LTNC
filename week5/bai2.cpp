#include <iostream>

using namespace std;

int size_ (int *a)
{
    return sizeof(a);
}

int main()
{
    int n; cin >> n;
    int a[n];
    cout << sizeof(a) << endl;
    cout << size_(a);
    return 0;
}
