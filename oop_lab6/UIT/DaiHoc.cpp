#include "DaiHoc.h"

void DaiHoc::Nhap() {
    SinhVien::Nhap();
    cin.ignore();
    cout << "Ten luan van: "; getline(cin, tenLuanVan);
    cout << "Diem luan van: "; cin >> diemLuanVan;
}

void DaiHoc::Xuat() {
    SinhVien::Xuat();
    cout << ", Ten LV: " << tenLuanVan << ", Diem LV: " << diemLuanVan << endl;
}

bool DaiHoc::TotNghiep() {
    return tongTinChi >= 170 && diemTB >= 5 && diemLuanVan >= 5;
}