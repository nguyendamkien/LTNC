#include <iostream>

using namespace std;

bool check(char m, string s)
{
    for(int i=0; i<s.length(); i++)
        if(m == s[i]) return true;
    return false;
}

void dequy(int n, int k, string s)
{
    if(k==0)
    {
        cout << s << endl;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(!check(char(i+'0'), s))
        s += char(i+'0');
        else continue;
        dequy(n, k-1, s);
        s.erase(s.begin() + s.length() - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    string s = "";
    dequy(n, n, s);
    return 0;
}
