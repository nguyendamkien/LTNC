#include <iostream>

using namespace std;

char* reverse(char a[])
{
    int t = sizeof a;
    char *b = new char [t];
    for(int i=0; i<t; i++)
    {
        *(b+i) = a[t-i];
    }
    return b;
}

int main()
{
    char *a = "abcdef";
    int t = sizeof(a);
    cout << t;
    char* b = reverse(a);
    for(int i=0; i<t; i++)
        cout << *(b+i);
    return 0;
}
