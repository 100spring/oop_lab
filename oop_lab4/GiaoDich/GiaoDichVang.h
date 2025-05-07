#ifndef GIAODICHVANG_H
#define GIAODICHVANG_H

#include "GiaoDich.h"

class GiaoDichVang : public Trade{
    protected:
        string loaiVang;
    public:
        void NhapVang();
        void XuatVang();
        double ThanhTienVang();
};

#endif 