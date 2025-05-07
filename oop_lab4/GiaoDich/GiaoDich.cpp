#include "GiaoDich.h"

void Trade::Nhap(){
    cin.ignore();
    cout << "Nhập mã giao dịch: "; getline(cin, maGD);
    cout << "Nhập ngày giao dịch(DD MM YYYY): "; getline(cin, ngayGD);
    cout << "Nhập đơn giá mỗi giao dịch: "; cin >> donGia;
    cout << "Nhập số lượng giao dịch: "; cin >> soLuong;
}

void Trade::Xuat(){
    cout << "Mã giao dịch: " << maGD << endl;
    cout << "Ngày giao dịch: " << ngayGD << endl;
    cout << "Đơn giá mỗi giao dịch: " << donGia << endl;
    cout << "Số lượng giao dịch: " << soLuong << endl;
} 