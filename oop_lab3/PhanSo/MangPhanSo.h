#include "PhanSo.cpp"
#include <vector>

class DSPhanSo : public PhanSo{
    protected:
        vector<PhanSo> MangPhanSo;
    public:
        DSPhanSo();
        ~DSPhanSo();
        void Nhap();
        void Xuat();
        PhanSo Tong();
        PhanSo PSLonNhat();
        PhanSo PSNhoNhat();
        PhanSo NguyenToLonNhat();
        void SXTangDan();
        void SXGiamDan();
};