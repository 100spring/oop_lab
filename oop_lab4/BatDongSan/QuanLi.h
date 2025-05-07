#ifndef QUANLI_H
#define QUANLI_H

#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
#include "GiaoDichChungCu.h"
#include <vector>
#include <climits>

class QuanLi {
private:
    vector<GiaoDichDat> GDDat;
    vector<GiaoDichNhaPho> GDNhaPho;
    vector<GiaoDichChungCu> GDChungCu;
public:
    void NhapGiaoDichDat();
    void NhapGiaoDichNhaPho();
    void NhapGiaoDichChungCu();
    void SoLuong();
    void TrungBinhChungCu();
    void NhaPhoCaoNhat();
    void GiaoDichThang12();
    void menu();
};

#endif