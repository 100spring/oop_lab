#include "LoaiA.h"

void LoaiA::Nhap(){
    KhachHang::Nhap();
}

void LoaiA::Xuat(){
    KhachHang::Xuat();
    cout << "Loại khách hàng: Bình thường (A)" << endl;
}

double LoaiA::TinhSoTienPhaiTra(){
    return soluonghang * dongiahang * 1.1;
}