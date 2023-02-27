#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    char a[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        cin >> a[i][j];
    int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    char c[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        if(a[i][j] == '*') c[i][j] = a[i][j];
        else {
                int dem = 0;
                for(int p=0; p<8; p++){
                        int newi = i+di[p];
                        int newj = j+dj[p];
                        if(newi>=0 && newj>=0 && newi<m && newj<n)
                            if(a[newi][newj] == '*') dem++;
                }

                c[i][j] = char(dem+'0');
        }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    return 0;
}
