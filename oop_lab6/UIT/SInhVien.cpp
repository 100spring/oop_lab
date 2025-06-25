#include "SinhVien.h"

void SinhVien::Nhap() {
    cout << "Ma SV: "; cin >> maSV;
    cin.ignore();
    cout << "Ho ten: "; getline(cin, hoTen);
    cout << "Dia chi: "; getline(cin, diaChi);
    cout << "Tong tin chi: "; cin >> tongTinChi;
    cout << "Diem TB: "; cin >> diemTB;
}

void SinhVien::Xuat() {
    cout << "Ma SV: " << maSV << ", Ho ten: " << hoTen << ", Dia chi: " << diaChi << ", Tong tin chi: " << tongTinChi << ", Diem TB: " << diemTB;
}