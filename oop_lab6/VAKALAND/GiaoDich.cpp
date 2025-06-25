#include "GiaoDich.h"

void GiaoDich::Nhap() {
    cout << "Ma giao dich: "; cin >> maGD;
    cout << "Ngay giao dich (dd/mm/yyyy): "; cin >> ngayGD;
    cout << "Don gia: "; cin >> donGia;
    cout << "Dien tich: "; cin >> dienTich;
}

void GiaoDich::Xuat() {
    cout << "Ma GD: " << maGD << ", Ngay GD: " << ngayGD << ", Don gia: " << donGia << ", Dien tich: " << dienTich;
}