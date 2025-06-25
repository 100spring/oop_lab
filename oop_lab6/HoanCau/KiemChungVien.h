#pragma once
#include "NhanVien.h"

class KiemChungVien : public NhanVien {
    int soLoi;
public:
    void Nhap() override;
    void Xuat() override;
    double TinhLuong() override;
    string getLoai() override { return "KT"; }
};