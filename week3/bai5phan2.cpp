#include <bits/stdc++.h>

using namespace std;

struct sinhvien{
    string name;
    double toan;
    double ly;
    double anh;
    double trungbinh()
    {
        return (toan+ly+anh)/3;
    }
};

bool theotoan(const sinhvien a, const sinhvien b)
{
    return (a.toan > b.toan);
}

bool theoly(const sinhvien a, const sinhvien b)
{
    return (a.ly > b.ly);
}

bool theotb(sinhvien a,sinhvien b)
{
    return (a.trungbinh() > b.trungbinh());
}

int main()
{
    int n; cin >> n;
    sinhvien f[n];
    for(int i=0; i<n; i++)
        cin >> f[i].name >> f[i].toan >> f[i].ly >> f[i].anh;
    sort(f,f+n,theotoan);
    cout << "Theo diem mon Toan"<< endl;
    for(int i=0; i<n; i++)
        cout <<f[i].name << "   " << f[i].toan << "   "<< f[i].ly << "   "<< f[i].anh << endl;
    sort(f,f+n,theoly);
    cout << "Theo diem mon ly" << endl;
    for(int i=0; i<n; i++)
        cout <<f[i].name << "   " << f[i].toan << "   "<< f[i].ly << "   "<< f[i].anh << endl;
        sort(f,f+n,theotb);
    cout << "Theo diem trung binh" << endl;
    for(int i=0; i<n; i++)
        cout <<f[i].name << "   " <<f[i].trungbinh() << "   " << f[i].toan << "   "<< f[i].ly << "   "<< f[i].anh << endl;
    return 0;
}
