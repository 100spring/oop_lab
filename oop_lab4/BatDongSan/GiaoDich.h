#ifndef GIAODICH_H
#define GIAODICH_H

#include <iostream>
#include <string>
using namespace std;

class GiaoDich {
protected:
    string maGD, ngayGD;
    double dongia, dientich;
public:
    void Nhap();
    void Xuat();
    string getNgayGD(){return ngayGD;}
};

#endif