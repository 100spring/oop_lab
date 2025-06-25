#include "CongTy.h"

int main(){
    CongTy xyz;

    xyz.NhapDanhSach();
    xyz.XuatKetQua();
    
    xyz.TinhTongSoTien();
    
    xyz.DocFile("XYZ.INP");
    xyz.GhiFile("XYZ.OUT");
    
    return 0;
}