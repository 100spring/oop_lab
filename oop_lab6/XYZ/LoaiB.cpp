#include "LoaiB.h"
#include <algorithm>

void LoaiB::Nhap(){
    KhachHang::Nhap();
    cout << "Nhập số năm thân thiết: "; cin >> sonamthanthiet;
}

void LoaiB::Xuat(){
    KhachHang::Xuat();
    cout << "Số năm thân thiết: " << sonamthanthiet << endl;
    cout << "Loại khách hàng: Thân thiết (B)" << endl;
}

double LoaiB::TinhSoTienPhaiTra(){
    double phantramkhuyenmai = min(sonamthanthiet * 0.05, 0.5);
    return soluonghang * dongiahang * (1.0 - phantramkhuyenmai) * 1.1;
}