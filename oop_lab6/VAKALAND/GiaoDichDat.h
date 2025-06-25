#pragma once
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich {
    protected:
        string loaiDat;
    public:
        void Nhap() override;
        void Xuat() override;
        double TinhTien() override;
};