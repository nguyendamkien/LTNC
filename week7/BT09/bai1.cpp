#include <iostream>

using namespace std;

int length(const char* s)
{
    int i = 0;
    int n = 0;
    while(s[i] != NULL)
    {
        n++;
        i++;
    }
    return n;
}

char* concat(const char* s, const char* t)
{
    char* w = new char [10];
    //int s1 = length(s);

    //int t1 = length(t);
    //w = new char [s1+t1];
    for(int i = 0; i<5; i++)
        w[i] = s[i];
    for(int i = 5; i < 10; i++)
        w[i] = t[i-5];
    w[10] = '\0';
    return w;
}

int main()
{
    const char* s = new char;
    s = "Hello";
    const char* t = new char;
    t = "World";
    char* m = new char [10];
    m = concat(s,t);
    cout << m;
    return 0;
}
