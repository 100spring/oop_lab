#pragma once
#include "LapTrinhVien.h"
#include "KiemChungVien.h"
#include <vector>

class QuanLi {
    vector<LapTrinhVien> dsLT;
    vector<KiemChungVien> dsKT;
public:
    void Nhap();
    void Xuat();
    void XuatLuongThapHonTB();
    void NhanVienLuongCaoNhat();
    void NhanVienLuongThapNhat();
    void LapTrinhLuongCaoNhat();
    void KiemChungLuongThapNhat();
};