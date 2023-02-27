#include <iostream>

using namespace std;

int main()
{
    int m; int n;
    cin >> m >> n;
    int a[m][n];
    int k=1;
    int hang=m, cot=n;
    int p=0;
    while(k<=m*n)
    {
        for(int i=p; i<cot; i++)
            {
                a[p][i] = k;
                k++;
            }
        cout << endl;
        for(int i=p+1; i<hang; i++)
        {
            a[i][cot-1] = k;
            k++;
        }
        if(p!=hang-1){
        for(int i=cot-2; i>=p; i--)
        {
            a[hang-1][i] = k;
            k++;
        }
        }
        if(p!=cot-1){
        for(int i=hang-2; i>=p+1; i--)
        {
            a[i][p] = k;
            k++;
        }
        }
        cot--;
        hang--;
        p++;



    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
        cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
