#include "LoaiC.h"

void LoaiC::Nhap(){
    KhachHang::Nhap();
}

void LoaiC::Xuat(){
    KhachHang::Xuat();
    cout << "Loại khách hàng: Đặc biệt (C)" << endl;
}

double LoaiC::TinhSoTienPhaiTra(){
    return soluonghang * dongiahang * 0.5 * 1.1;
}