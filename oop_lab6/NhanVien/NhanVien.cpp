#include "NhanVien.h"

void NhanVien::Nhap(){
    cout << "Nhập họ tên: "; getline(cin, hoten);
    cout << "Nhập ngày sinh: "; cin >> ngaysinh;
}

void NhanVien::Xuat(){
    cout << "Họ tên: " << hoten << endl;
    cout << "Ngày sinh: " << ngaysinh << endl;
}