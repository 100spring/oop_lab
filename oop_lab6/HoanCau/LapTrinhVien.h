#pragma once
#include "NhanVien.h"

class LapTrinhVien : public NhanVien {
    int soGioOT;
public:
    void Nhap() override;
    void Xuat() override;
    double TinhLuong() override;
    string getLoai() override { return "LT"; }
};