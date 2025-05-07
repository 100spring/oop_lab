#ifndef QUANLI_H
#define QUANLI_H

#include "GiaoDichVang.h"
#include "GiaoDichTienTe.h"
#include <climits>


class QuanLi{
    private:
        vector<GiaoDichVang> GDV;
        vector<GiaoDichTienTe> GDTT;
    public:
        void GiaoDichVangCaoNhat();
        void GiaoDichEURThapNhat();
        void GiaoDichGiaTriCao();
        void menu();
};

#endif 