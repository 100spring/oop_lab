#include "QuanLi.h"

void QuanLi::Nhap() {
    int n;
    cout << "So lap trinh vien: "; cin >> n;
    dsLT.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Lap trinh vien thu " << i + 1 << ":\n";
        dsLT[i].Nhap();
    }

    cout << "So kiem chung vien: "; cin >> n;
    dsKT.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Kiem chung vien thu " << i + 1 << ":\n";
        dsKT[i].Nhap();
    }
}

void QuanLi::Xuat() {
    cout << "\nDANH SACH LAP TRINH VIEN:\n";
    for (int i = 0; i < dsLT.size(); i++) {
        dsLT[i].Xuat();
    }

    cout << "\nDANH SACH KIEM CHUNG VIEN:\n";
    for (int i = 0; i < dsKT.size(); i++) {
        dsKT[i].Xuat();
    }
}

void QuanLi::XuatLuongThapHonTB() {
    double tongLuong = 0;
    int tongNV = dsLT.size() + dsKT.size();

    for (int i = 0; i < dsLT.size(); i++) tongLuong += dsLT[i].TinhLuong();
    for (int i = 0; i < dsKT.size(); i++) tongLuong += dsKT[i].TinhLuong();

    double trungBinh = tongLuong / tongNV;

    cout << "\nNHAN VIEN CO LUONG THAP HON TB (" << trungBinh << "):\n";

    for (int i = 0; i < dsLT.size(); i++) {
        if (dsLT[i].TinhLuong() < trungBinh) dsLT[i].Xuat();
    }

    for (int i = 0; i < dsKT.size(); i++) {
        if (dsKT[i].TinhLuong() < trungBinh) dsKT[i].Xuat();
    }
}

void QuanLi::NhanVienLuongCaoNhat() {
    double maxLuong = 0;
    int indexLT = -1, indexKT = -1;

    for (int i = 0; i < dsLT.size(); i++) {
        double l = dsLT[i].TinhLuong();
        if (l > maxLuong) {
            maxLuong = l;
            indexLT = i;
            indexKT = -1;
        }
    }

    for (int i = 0; i < dsKT.size(); i++) {
        double l = dsKT[i].TinhLuong();
        if (l > maxLuong) {
            maxLuong = l;
            indexLT = -1;
            indexKT = i;
        }
    }

    cout << "\nNHAN VIEN CO LUONG CAO NHAT:\n";
    if (indexLT != -1) dsLT[indexLT].Xuat();
    else dsKT[indexKT].Xuat();
}

void QuanLi::NhanVienLuongThapNhat() {
    double minLuong = 1e9;
    int indexLT = -1, indexKT = -1;

    for (int i = 0; i < dsLT.size(); i++) {
        double l = dsLT[i].TinhLuong();
        if (l < minLuong) {
            minLuong = l;
            indexLT = i;
            indexKT = -1;
        }
    }

    for (int i = 0; i < dsKT.size(); i++) {
        double l = dsKT[i].TinhLuong();
        if (l < minLuong) {
            minLuong = l;
            indexLT = -1;
            indexKT = i;
        }
    }

    cout << "\nNHAN VIEN CO LUONG THAP NHAT:\n";
    if (indexLT != -1) dsLT[indexLT].Xuat();
    else dsKT[indexKT].Xuat();
}

void QuanLi::LapTrinhLuongCaoNhat() {
    if (dsLT.empty()) return;
    int index = 0;
    for (int i = 1; i < dsLT.size(); i++) {
        if (dsLT[i].TinhLuong() > dsLT[index].TinhLuong())
            index = i;
    }
    cout << "\nLAP TRINH VIEN CO LUONG CAO NHAT:\n";
    dsLT[index].Xuat();
}

void QuanLi::KiemChungLuongThapNhat() {
    if (dsKT.empty()) return;
    int index = 0;
    for (int i = 1; i < dsKT.size(); i++) {
        if (dsKT[i].TinhLuong() < dsKT[index].TinhLuong())
            index = i;
    }
    cout << "\nKIEM CHUNG VIEN CO LUONG THAP NHAT:\n";
    dsKT[index].Xuat();
}