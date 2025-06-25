#pragma once
#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string maNV, hoTen, sdt, email;
    int tuoi;
    double luongCoBan;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong() = 0;
    virtual string getLoai() = 0;
};