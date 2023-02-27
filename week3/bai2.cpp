#include <iostream>

using namespace std;

int main()
{
    string s; cin >> s;
    int t = s.length();
    for(int i=0; i<=-1+t/2; i++)
        if(s[i]!=s[t-1-i])
    {
        cout << "no";
        return 0;
    }
    cout << "yes";
    return 0;
}
