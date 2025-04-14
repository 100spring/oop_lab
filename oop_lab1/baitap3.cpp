#include <iostream>
using namespace std;

struct phanso{
    int tuso, mauso;
};

phanso operator+(phanso a, phanso b){
    phanso temp;
    temp.tuso = a.tuso*b.mauso + b.tuso*a.mauso;
    temp.mauso = a.mauso*b.mauso;
    return temp;
}

phanso operator-(phanso a, phanso b){
    phanso temp;
    temp.tuso = a.tuso*b.mauso - b.tuso*a.mauso;
    temp.mauso = a.mauso*b.mauso;
    return temp;
}

phanso operator*(phanso a, phanso b){
    phanso temp;
    temp.tuso = a.tuso*b.tuso;
    temp.mauso = a.mauso*b.mauso;
    return temp;
}

phanso operator/(phanso a, phanso b){
    phanso temp;
    temp.tuso = a.tuso*b.mauso;
    temp.mauso = a.mauso*b.tuso;
    return temp;
}

int main(){
    phanso m, n;
    // nhập phân số thứ nhất
    do{
        cout << "Nhap phan so thu nhat: " << endl;
        cout << "Nhap tu so: "; cin >> m.tuso;
        cout << "Nhap mau so: "; cin >> m.mauso;
        if(m.mauso == 0)
            cout << "Mau so phai khac 0. Yeu cau nhap lai." << endl;
    }
    while(m.mauso == 0);
    // nhập phân số thứ hai
    do{
        cout << "Nhap phan so thu hai: " << endl;
        cout << "Nhap tu so: "; cin >> n.tuso;
        cout << "Nhap mau so: "; cin >> n.mauso;
        if(n.mauso == 0)
            cout << "Mau so phai khac 0. Yeu cau nhap lai." << endl;
    }
    while(n.mauso == 0);

    phanso k;
    k = m + n;
    cout << "tong hai phan so la: " << k.tuso << "/" << k.mauso << endl;
    k = m - n;
    cout << "hieu hai phan so la: " << k.tuso << "/" << k.mauso << endl;
    k = m * n;
    cout << "tich hai phan so la: " << k.tuso << "/" << k.mauso << endl;
    k = m / n;
    cout << "thuong hai phan so la: " << k.tuso << "/" << k.mauso;

    return 0;
}