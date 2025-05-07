
#ifndef GIAODICHNH_H
#define GIAODICHNH_H

#include "GiaoDich.h"

class GiaoDichNhaPho : public GiaoDich {
protected:
    string loainha, diachi;
public:
    void Nhap();
    void Xuat();
    double ThanhTien();
};

#endif