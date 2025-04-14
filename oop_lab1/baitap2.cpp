#include <iostream>
using namespace std;

struct phanSo{
    int tuSo, mauSo;
};

bool soSanhPhanSo(phanSo a, phanSo b){
    int k = a.tuSo*b.mauSo - b.tuSo*a.mauSo;
    if(k < 0)
        return true;
    return false;
}

int main(){
    phanSo a, b;
    // nhập phân số thứ nhất
    do{
        cout << "Nhap phan so thu nhat: " << endl;
        cout << "Nhap tu so: "; cin >> a.tuSo;
        cout << "Nhap mau so: "; cin >> a.mauSo;
        if(a.mauSo == 0)
            cout << "Mau so phai khac 0. Yeu cau nhap lai." << endl;
    }
    while(a.mauSo == 0);
    // nhập phân số thứ hai
    do{
        cout << "Nhap phan so thu hai: " << endl;
        cout << "Nhap tu so: "; cin >> b.tuSo;
        cout << "Nhap mau so: "; cin >> b.mauSo;
        if(b.mauSo == 0)
            cout << "Mau so phai khac 0. Yeu cau nhap lai." << endl;
    }
    while(b.mauSo == 0);
    if(soSanhPhanSo(a, b))
        cout << "Phan so lon hon la: " << b.tuSo << "/" << b.mauSo;
    else 
        cout << "Phan so lon hon la: " << a.tuSo << "/" << a.mauSo;
    return 0;
}