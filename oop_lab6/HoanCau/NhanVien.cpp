#include "NhanVien.h"

void NhanVien::Nhap() {
    cout << "Ma NV: "; cin >> maNV;
    cin.ignore();
    cout << "Ho ten: "; getline(cin, hoTen);
    cout << "Tuoi: "; cin >> tuoi;
    cin.ignore();
    cout << "SDT: "; getline(cin, sdt);
    cout << "Email: "; getline(cin, email);
    cout << "Luong co ban: "; cin >> luongCoBan;
}

void NhanVien::Xuat() {
    cout << "Ma NV: " << maNV << ", Ho ten: " << hoTen
         << ", Tuoi: " << tuoi << ", SDT: " << sdt
         << ", Email: " << email << ", Luong co ban: " << luongCoBan;
}