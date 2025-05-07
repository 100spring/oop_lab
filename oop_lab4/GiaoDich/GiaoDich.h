#ifndef GIAODICH_H
#define GIAODICH_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trade{
    protected:
        string maGD, ngayGD;
        double donGia;
        int soLuong;
    public:
        void Nhap();
        void Xuat();
};

#endif 