#pragma once
#include "SinhVien.h"

class CaoDang : public SinhVien {
    double diemTotNghiep;
public:
    void Nhap() override;
    void Xuat() override;
    bool TotNghiep() override;
    string getLoai() override { return "CD"; }
};