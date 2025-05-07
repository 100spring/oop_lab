#include "GiaoDichVang.h"

void GiaoDichVang::NhapVang(){
    Trade::Nhap();
    cout << "Nhập loại vàng: "; 
    cin.ignore();
    getline(cin, loaiVang);
}

void GiaoDichVang::XuatVang(){
    Trade::Xuat();
    cout << "Loại vàng: " << loaiVang << endl;
}

double GiaoDichVang::ThanhTienVang(){
    return soLuong*donGia;
}