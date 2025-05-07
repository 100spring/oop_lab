#ifndef GIAODICHDAT_H
#define GIAODICHDAT_H

#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich {
protected:
    string loaidat;
public:
    double ThanhTien();
    void Nhap();
    void Xuat();
};

#endif