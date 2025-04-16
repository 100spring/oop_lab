#include "NhanVien.cpp"

class DanhSach : public NhanVien{
    protected:
        vector<NhanVien> DSNhanVien;
    public:
        void Nhap();
        void Xuat();
        void LuongCaoNhat();
        void TongLuong();
        void TuoiCaoNhat();
        void SXTangTheoLuong();
};