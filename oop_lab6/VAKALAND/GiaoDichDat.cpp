#include "GiaoDichDat.h"

void GiaoDichDat::Nhap() {
    GiaoDich::Nhap();
    cout << "Loai dat (A/B/C): "; cin >> loaiDat;
}

void GiaoDichDat::Xuat() {
    GiaoDich::Xuat();
    cout << ", Loai dat: " << loaiDat << ", Thanh tien: " << TinhTien() << endl;
}

double GiaoDichDat::TinhTien() {
    if (loaiDat == "A") return dienTich * donGia * 1.5;
    return dienTich * donGia;
}