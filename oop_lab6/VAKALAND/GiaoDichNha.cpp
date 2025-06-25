#include "GiaoDichNha.h"

void GiaoDichNha::Nhap() {
    GiaoDich::Nhap();
    cout << "Loai nha (cao cap/thuong): "; cin.ignore(); getline(cin, loaiNha);
    cout << "Dia chi: "; getline(cin, diaChi);
}

void GiaoDichNha::Xuat() {
    GiaoDich::Xuat();
    cout << ", Loai nha: " << loaiNha << ", Dia chi: " << diaChi << ", Thanh tien: " << TinhTien() << endl;
}

double GiaoDichNha::TinhTien() {
    if (loaiNha == "thuong") return dienTich * donGia * 0.9;
    return dienTich * donGia;
}
