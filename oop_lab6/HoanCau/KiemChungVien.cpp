#include "KiemChungVien.h"

void KiemChungVien::Nhap() {
    NhanVien::Nhap();
    cout << "So loi phat hien: "; cin >> soLoi;
}

void KiemChungVien::Xuat() {
    NhanVien::Xuat();
    cout << ", So loi: " << soLoi
         << ", Luong: " << TinhLuong() << endl;
}

double KiemChungVien::TinhLuong() {
    return luongCoBan + soLoi * 50000;
}