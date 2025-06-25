#include "LapTrinhVien.h"

void LapTrinhVien::Nhap() {
    NhanVien::Nhap();
    cout << "So gio OT: "; cin >> soGioOT;
}

void LapTrinhVien::Xuat() {
    NhanVien::Xuat();
    cout << ", So gio OT: " << soGioOT
         << ", Luong: " << TinhLuong() << endl;
}

double LapTrinhVien::TinhLuong() {
    return luongCoBan + soGioOT * 200000;
}