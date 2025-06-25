#include "LoaiA.h"
#include "LoaiB.h"
#include "LoaiC.h"
#include <fstream>

class CongTy{
    private:
        vector<LoaiA> listA;
        vector<LoaiB> listB;
        vector<LoaiC> listC;
    public:
        void NhapDanhSach();
        void XuatKetQua();
        void TinhTongSoTien();
        void DocFile(string filename);
        void GhiFile(string filename);
};