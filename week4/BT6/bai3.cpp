#include <bits/stdc++.h>

using namespace std;

bool kiemtra(char m, string s)
{
    for(int i=0; i<s.length();i++)
        if(s[i] == m) return false;
    return true;
}

void dequy(int n, int k, string s)
{
    if(k == 0)
    {
        cout << s << endl;
        return ;
    }
    char last = (s.size()==0 ? 'a' : s.back()+1);
    for(char i = last; i <= 'a' + n - 1; i++)
    {
        if(kiemtra(i, s)) s += i;
        else continue;
        dequy(n, k-1, s);
        s.erase(s.begin() + s.length()-1);

    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s = "";
    dequy(n, k , s);
    return 0;
}
