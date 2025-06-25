#include "NhanVien.h"

class SanXuat : public NhanVien{
    protected:
        double luongcoban;
        int sosanpham;
    public:
        void Nhap();
        void Xuat();
        double TinhLuong();
};