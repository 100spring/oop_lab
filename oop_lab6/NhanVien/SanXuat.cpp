#include "SanXuat.h"

void SanXuat::Nhap(){
    NhanVien::Nhap();
    cout << "Nhập lương cơ bản: "; cin >> luongcoban;
    cout << "Nhập số sản phẩm: "; cin >> sosanpham;
}

void SanXuat::Xuat(){
    NhanVien::Xuat();
    cout << "Lương cơ bản: " << luongcoban << endl;
    cout << "Số sản phẩm: " << sosanpham << endl;
}

double SanXuat::TinhLuong(){
    return luongcoban + sosanpham*5000.0;
}