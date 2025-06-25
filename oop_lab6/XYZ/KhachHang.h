#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KhachHang{
    protected:
        string tenkhachhang;
        int soluonghang;
        double dongiahang;
    public:
        void Nhap();
        void Xuat();
        string getTenKhachHang() {return tenkhachhang;}
        int getSoLuongHang() {return soluonghang;}
        double getDonGiaHang() {return dongiahang;}
        virtual double TinhSoTienPhaiTra() = 0;
};