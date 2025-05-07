#ifndef GIAODICHTIENTE_H
#define GIAODICHTIENTE_H

#include "GiaoDich.h"

class GiaoDichTienTe : public Trade{
    protected:
        string loaiTienTe;
        double tiGia;
    public:
        void NhapTienTe();
        void XuatTienTe();
        double ThanhTien();
        string getType();
};

#endif 