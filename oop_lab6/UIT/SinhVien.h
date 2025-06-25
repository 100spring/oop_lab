#pragma once
#include <iostream>
#include <string>
using namespace std;

class SinhVien {
protected:
    string maSV, hoTen, diaChi;
    int tongTinChi;
    double diemTB;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual bool TotNghiep() = 0;
    double getDiemTB() { return diemTB; }
    virtual string getLoai() = 0;
};