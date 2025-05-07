#include "GiaoDich.h"

void GiaoDich::Nhap(){
    cin.ignore();
    cout << "Nhập mã giao dịch: "; getline(cin, maGD);
    cout << "Nhập ngày giao dịch(DD MM YYYY): "; getline(cin, ngayGD);
    cout << "Nhập đơn giá: "; cin >> dongia;
    cout << "Nhập diện tích: "; cin >> dientich;
}

void GiaoDich::Xuat(){
    cout << "Mã giao dịch: " << maGD << endl;
    cout << "Ngày giao dịch: " << ngayGD << endl;
    cout << "Đơn giá: " << dongia << endl; 
    cout << "Diện tích: " << dientich << endl;
}