#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int t = s.length();

    for(int i=0; i<t; i++)
        for(int j=0; j<t; j++)
        {

            cout << (char)(s[i]) << (char)(s[j]) << " ";
            for(int k=0; k<t; k++)
                cout << (char)(s[i]) << char(s[j]) << (char)(s[k]) << " ";
        }
    return 0;
}
