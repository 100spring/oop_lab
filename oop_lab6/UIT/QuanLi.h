#pragma once
#include "CaoDang.h"
#include "DaiHoc.h"
#include <vector>

class QuanLi {
    vector<CaoDang> dsCD;
    vector<DaiHoc> dsDH;
public:
    void Nhap();
    void Xuat();
    void DS_TotNghiep();
    void DS_KhongTotNghiep();
    void CD_DiemTBCaoNhat();
    void DH_DiemTBCaoNhat();
    void Dem_KhongTotNghiep();
};
