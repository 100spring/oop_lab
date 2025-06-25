#pragma once
#include "GiaoDich.h"

class GiaoDichChungCu : public GiaoDich {
    protected:
        string maCan;
        int viTriTang;
    public:
        void Nhap() override;
        void Xuat() override;
        double TinhTien() override;
};