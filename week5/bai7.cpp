#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char *str1;
    char *str2;
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    str1 = new char [n1];
    str2 = new char [n2];
    for(int i=0; i<n1; i++)
        *(str1 + i) = s1[i];
    int s = 0;
    int j = 0;
    while(j+n1<=n2)
    {
        for(int k = j; k < j+n1; k++)
            *(str2 + k - j) = s2[k];
            if(strcmp(str1, str2) == 0) s++;
        j++;
    }
    cout << s;


}
