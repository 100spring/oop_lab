#include "Diem.cpp"

class DaGiac: public Diem{
    protected:
        vector<Diem> GocDaGiac;
    public:
        DaGiac();
        ~DaGiac();
        void Nhap();
        void Xuat();
        double ChuVi();
        double DienTich();
        void TinhTien();
        void PhongTo();
        void Quay();
};