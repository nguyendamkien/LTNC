#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    int m, n, k;
    cin >> m >> n >> k;
    char a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            a[i][j] = '-';
    srand(time(0));
    for(int i=0; i<k; i++)
    {
        int x = rand() % m;
        int y = rand() % n;
        if(a[x][y] == '*') i--;
        else a[x][y] = '*';
    }
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    while(1)
    {
        int x, y;
        cin >> x >> y;
        if (a[x-1][y-1] == '*')
        {
            cout << "YOU'RE DEAD!" << endl;
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                    cout << a[i][j];
                    cout << endl;

            }
        }
        else
        {
            int i = x-1;
            int j = y-1;
            int sum = 0;
            for(int k=0; k<8; k++)
            {
                int newi = i + dy[k];
                int newj = j + dx[k];
                if(newi >= 0 && newi < m && newj >=0 && newj < n && a[newi][newj] == '*') sum++;
            }
            a[i][j] = (char)(sum + '0') ;
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                    if(a[i][j] == '*') cout << '-';
                    else cout << a[i][j];
                    cout << endl;

            }
        }
    }
    return 0;
}

