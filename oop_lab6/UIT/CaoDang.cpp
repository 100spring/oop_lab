#include "CaoDang.h"

void CaoDang::Nhap() {
    SinhVien::Nhap();
    cout << "Diem thi tot nghiep: "; cin >> diemTotNghiep;
}

void CaoDang::Xuat() {
    SinhVien::Xuat();
    cout << ", Diem TN: " << diemTotNghiep << endl;
}

bool CaoDang::TotNghiep() {
    return tongTinChi >= 120 && diemTB >= 5 && diemTotNghiep >= 5;
}