
#ifndef GIAODICHCC_H
#define GIAODICHCC_H

#include "GiaoDich.h"

class GiaoDichChungCu : public GiaoDich {
protected:
    string macan;
    int vitritang;
public:
    void Nhap();
    void Xuat();
    double ThanhTien();
};

#endif