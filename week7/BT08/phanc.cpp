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

char* reverse_(char a[])
{
    int t = length(a);
    char *b = new char [t];
    for(int i=0; i<t; i++)
    {
        b[i] = a[t-i-1];
    }
    b[t] = '\0';
    return b;
}

char* delete_char(char a[], char c)
{
    int m =0;
    int t = length(a);

    for(int i=0; i<t; i++)
    {
        if(a[i] == c) m++;
    }
    char *b = new char [t - m];
    int s = 0;
    for(int i=0; i<t; i++)
    {
        if(a[i] != c)
        {
            b[s] = a[i];
            s++;
        }
        else continue;
    }
    b[t] = '\0';
    return b;

}

char* pad_right(char a[], int n)
{
    int t = length(a);
    char* b = new char [n];
    if(n <= t) return a;
    else
    {
        for(int i=0; i<t; i++)
            b[i] = a[i];
        for(int i=t; i<n; i++)
            b[i] = '-';

        b[n] = '\0';
        return b;
    }
}

char* pad_left(char a[], int n)
{
    int t = length(a);
    char* b = new char [n];
    if(n <= t) return a;
    else
    {
        for(int i=0; i<=n-t-1; i++)
            b[i] = '-';
        for(int i=n-t; i<n; i++)
            b[i] = a[i-n+t];

        b[n] = '\0';
        return b;
    }
}

char* truncate(char a[], int n)
{
    int t = length(a);
    char* b = new char [n];
    if(n >= t) return a;
    else
    {
        for(int i=0; i<n; i++)
            b[i] = a[i];
        b[n] = '\0';
        return b;
    }
}

 bool is_palindrome(char a[])
 {
     int t = length(a);
     for(int i =0; i<t/2; i++)
     {
         if(a[i] != a[t-i]) return false;
     }
     return true;
 }

int main()
{
    char* a = new char ;
    a = "abcdef";
    cout << reverse_(a) << endl;
    cout << delete_char(a, 'd') << endl;
    cout << pad_right(a, 10) << endl;
    cout << pad_left(a, 10) << endl;
    cout << truncate(a,3) << endl;
    if(is_palindrome(a)) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
