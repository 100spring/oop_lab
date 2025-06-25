#include "VanPhong.h"
#include "SanXuat.h"

class QuanLi{
    private:
        vector<VanPhong> listVP;
        vector<SanXuat> listSX;
    public:
        void Nhap();
        void XuatLuong();
        void Xuat();
        void TongLuong();
        void LuongSXThapNhat();
        void VanPhongCaoTuoi();
};