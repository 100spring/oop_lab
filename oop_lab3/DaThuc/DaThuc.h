#include "DonThuc.cpp"

class DaThuc : public DonThuc{
    protected:
        vector<DonThuc> DSDonThuc;
    public:
        void Nhap();
        void Xuat();
        void TinhGiaTri();
        static DaThuc Cong(DaThuc &p1, DaThuc &p2);
        static DaThuc Tru(DaThuc &p1, DaThuc &p2);
}; 