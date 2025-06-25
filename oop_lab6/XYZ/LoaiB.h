#include "KhachHang.h"

class LoaiB : public KhachHang{
    protected:
        int sonamthanthiet;
    public:
        void Nhap();
        void Xuat();
        double TinhSoTienPhaiTra();
        int getSoNamThanThiet() {return sonamthanthiet;}
};