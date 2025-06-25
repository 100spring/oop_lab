#include "VanPhong.h"

void VanPhong::Nhap(){
    NhanVien::Nhap();
    cout << "Nhập số ngày làm: "; cin >> songay;
}

void VanPhong::Xuat(){
    NhanVien::Xuat();
    cout << "Số ngày làm: " << songay << endl;
}

double VanPhong::TinhLuong(){
    return songay * 100000.0;
}