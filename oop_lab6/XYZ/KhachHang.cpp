#include "KhachHang.h"

void KhachHang::Nhap(){
    cout << "Nhập tên khách hàng: "; getline(cin, tenkhachhang);
    cout << "Nhập số lượng hàng: "; cin >> soluonghang;
    cout << "Nhập đơn giá hàng: "; cin >> dongiahang;
}

void KhachHang::Xuat(){
    cout << "Tên khách hàng: " << tenkhachhang << endl;
    cout << "Số lượng hàng: " << soluonghang << endl;
    cout << "Đơn giá hàng: " << dongiahang << endl;
}