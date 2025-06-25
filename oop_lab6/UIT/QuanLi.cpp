#include "QuanLi.h"

void QuanLi::Nhap() {
    int n;

    cout << "NHAP SINH VIEN CAO DANG\n";
    cout << "So luong SV CD: ";
    cin >> n;
    dsCD.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien cao dang thu " << i + 1 << ":\n";
        dsCD[i].Nhap();
    }

    cout << "NHAP SINH VIEN DAI HOC\n";
    cout << "So luong SV DH: ";
    cin >> n;
    dsDH.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien dai hoc thu " << i + 1 << ":\n";
        dsDH[i].Nhap();
    }
}

void QuanLi::Xuat() {
    cout << "\nDANH SACH SINH VIEN CAO DANG:\n";
    for (int i = 0; i < dsCD.size(); i++) {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        dsCD[i].Xuat();
    }

    cout << "\nDANH SACH SINH VIEN DAI HOC:\n";
    for (int i = 0; i < dsDH.size(); i++) {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        dsDH[i].Xuat();
    }
}

void QuanLi::DS_TotNghiep() {
    cout << "\nSINH VIEN CAO DANG TOT NGHIEP:\n";
    for (int i = 0; i < dsCD.size(); i++) {
        if (dsCD[i].TotNghiep())
            dsCD[i].Xuat();
    }

    cout << "\nSINH VIEN DAI HOC TOT NGHIEP:\n";
    for (int i = 0; i < dsDH.size(); i++) {
        if (dsDH[i].TotNghiep())
            dsDH[i].Xuat();
    }
}

void QuanLi::DS_KhongTotNghiep() {
    cout << "\nSINH VIEN CAO DANG KHONG TOT NGHIEP:\n";
    for (int i = 0; i < dsCD.size(); i++) {
        if (!dsCD[i].TotNghiep())
            dsCD[i].Xuat();
    }

    cout << "\nSINH VIEN DAI HOC KHONG TOT NGHIEP:\n";
    for (int i = 0; i < dsDH.size(); i++) {
        if (!dsDH[i].TotNghiep())
            dsDH[i].Xuat();
    }
}

void QuanLi::CD_DiemTBCaoNhat() {
    if (dsCD.empty()) return;

    int index = 0;
    for (int i = 1; i < dsCD.size(); i++) {
        if (dsCD[i].getDiemTB() > dsCD[index].getDiemTB()) {
            index = i;
        }
    }

    cout << "\nSINH VIEN CAO DANG CO DIEM TB CAO NHAT:\n";
    dsCD[index].Xuat();
}

void QuanLi::DH_DiemTBCaoNhat() {
    if (dsDH.empty()) return;

    int index = 0;
    for (int i = 1; i < dsDH.size(); i++) {
        if (dsDH[i].getDiemTB() > dsDH[index].getDiemTB()) {
            index = i;
        }
    }

    cout << "\nSINH VIEN DAI HOC CO DIEM TB CAO NHAT:\n";
    dsDH[index].Xuat();
}

void QuanLi::Dem_KhongTotNghiep() {
    int demCD = 0;
    int demDH = 0;

    for (int i = 0; i < dsCD.size(); i++) {
        if (!dsCD[i].TotNghiep())
            demCD++;
    }

    for (int i = 0; i < dsDH.size(); i++) {
        if (!dsDH[i].TotNghiep())
            demDH++;
    }

    cout << "\nSo sinh vien cao dang khong tot nghiep: " << demCD << endl;
    cout << "So sinh vien dai hoc khong tot nghiep: " << demDH << endl;
}