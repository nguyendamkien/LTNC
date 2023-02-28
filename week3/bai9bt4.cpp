#include <bits/stdc++.h>

using namespace std;

void sub1()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0 ; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int a[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        a[i][j] = 0;
    for(int i=0; i<n; i++)
    {
        if(a[x[i]-1][y[i]-1]==1){
            cout << "yes";
            return;
        }
        else{
            for(int j=0; j<n; j++)
            {
                a[x[i]-1][j] = 1;
                a[j][y[i]-1] = 1;
            }
            for(int j=0; j<n; j++)
            for(int k=0; k<n; k++){
                if(j+k == x[i] + y[i] - 2) a[j][k] = 1;
                if(j-k == x[i] - y[i]) a[j][k] = 1;
            }
        }

    }
    cout << "no";
    return;
}

/*void sub2()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0 ; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int row[n];
    int col[n];
    int cc[2 * n];
    int cp[2 * n];
    for(int i = 0; i < n; i++)
    {
        row[i] = 0;
        col[i] = 0;
    }
    for(int i = 0; i < 2 * n; i++)
    {
        cc[i] = 0;
        cp[i] = 0;
    }
    for(int i = 0; i<n; i++)
    {
        row[x[i]-1]++;
        col[y[i]-1]++;
        cc[n+y[i]-x[i]]++;
        cp[x[i]+y[i]]++;
    }
    for(int i = 0; i < n; i++)
        if(row[i] >= 2 || col[i] >= 2)
        {
            cout << yes;
            return 0;
        }
    for(int i = 0; i < 2 * n; i++)
        if(cc[i] >= 2 || cp[i] >= 2)
        {
            cout << yes;
            return;
        }
    cout << "no";
    return;
}*/




}

int main()
{
    sub1();
    return 0;
}
