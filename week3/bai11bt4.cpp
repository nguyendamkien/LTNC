#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    string s[n];
    for(int i=0; i < n; i++)
        cin >> s[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(s[j] == s[i])
            {
                cout << s[i].length() << " " << s[i][s[i].length()/2];
                return 0;
            }
        }
        s[i] = string(s[i].rbegin(), s[i].rend());

    }


    return 0;
}

