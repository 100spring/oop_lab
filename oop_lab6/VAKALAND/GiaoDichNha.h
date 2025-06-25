#pragma once
#include "GiaoDich.h"

class GiaoDichNha : public GiaoDich {
    protected:
        string loaiNha; 
        string diaChi;
    public:
        void Nhap() override;
        void Xuat() override;
        double TinhTien() override;
};