#pragma once
#include "SinhVien.h"

class DaiHoc : public SinhVien {
    string tenLuanVan;
    double diemLuanVan;
public:
    void Nhap() override;
    void Xuat() override;
    bool TotNghiep() override;
    string getLoai() override { return "DH"; }
};