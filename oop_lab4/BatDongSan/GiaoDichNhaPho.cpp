#include "GiaoDichNhaPho.h"

void GiaoDichNhaPho::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Loại nhà: "; getline(cin, loainha);
    cout << "Địa chỉ: "; getline(cin, diachi);
}

void GiaoDichNhaPho::Xuat(){
    GiaoDich::Xuat();
    cout << "Loại nhà: " << loainha << endl;
    cout << "Địa chỉ: " << diachi << endl;
}

double GiaoDichNhaPho::ThanhTien(){
    if(loainha == "cao cap")
        return dientich * dongia;
    else 
        return dientich * dongia * 0.9;
}