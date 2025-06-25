#include "GiaoDichChungCu.h"

void GiaoDichChungCu::Nhap() {
    GiaoDich::Nhap();
    cout << "Ma can: "; cin >> maCan;
    cout << "Vi tri tang: "; cin >> viTriTang;
}

void GiaoDichChungCu::Xuat() {
    GiaoDich::Xuat();
    cout << ", Ma can: " << maCan << ", Tang: " << viTriTang << ", Thanh tien: " << TinhTien() << endl;
}

double GiaoDichChungCu::TinhTien() {
    if (viTriTang == 1) return dienTich * donGia * 2;
    if (viTriTang >= 15) return dienTich * donGia * 1.2;
    return dienTich * donGia;
}