#include "NhanVien.h"

class VanPhong : public NhanVien{
    protected:
        int songay;
    public:
        void Nhap();
        void Xuat();
        double TinhLuong();
};