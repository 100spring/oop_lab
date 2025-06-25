#pragma once
#include "GiaoDichDat.h"
#include "GiaoDichNha.h"
#include "GiaoDichChungCu.h"
#include <vector>

class QuanLi {
    private:
        vector<GiaoDichDat> dsDat;
        vector<GiaoDichNha> dsNha;
        vector<GiaoDichChungCu> dsCC;
    public:
        void Nhap();
        void Xuat();
        void ThongKe();
        void TrungBinhChungCu();
        void NhaCaoNhat();
        void GiaoDichThang12();
};