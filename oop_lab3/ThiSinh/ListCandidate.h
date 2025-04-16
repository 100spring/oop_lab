#include "Candidate.cpp"

class ListCandidate : public Candidate{
    protected:
        vector<Candidate> DSThiSinh;
    public:
        void Nhap();
        void XuatTongDiemCao();
        void ThiSinhCaoDiemNhat();
        void TongDiemGiamDan();
};