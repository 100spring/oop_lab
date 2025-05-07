#include "GiaoDichChungCu.h"

void GiaoDichChungCu::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Mã căn: "; getline(cin, macan);
    cout << "Vị trí tầng: "; cin >> vitritang;
}

void GiaoDichChungCu::Xuat(){
    GiaoDich::Xuat();
    cout << "Mã căn: " << macan << endl;
    cout << "Vị trí tầng: " << vitritang << endl;
}

double GiaoDichChungCu::ThanhTien(){
    if(vitritang == 1)
        return dientich * dongia * 2;
    else if(vitritang >= 15)
        return dientich * dongia;
    else 
        return dientich * dongia * 1.2;
}