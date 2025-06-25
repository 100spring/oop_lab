#pragma once
#include <iostream>
#include <vector>
using namespace std;

class NhanVien{
    protected:
        string hoten;
        long long ngaysinh;
    public:
        void Nhap();
        void Xuat();
        string getHoTen() {return hoten;}
        int getNamSinh() {return ngaysinh % 10000;}
        virtual double TinhLuong() = 0;
};