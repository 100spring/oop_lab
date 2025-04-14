#include "SoPhuc.cpp"

int main(){
    soPhuc k, m, n;
    cout << "Nhập số phức thứ nhất." << endl;  m.Nhap();
    cout << "Nhập số phức thứ hai." << endl; n.Nhap();

    k = k.Tong(m, n);
    cout << "Tổng hai số phức là: ";
    k.Xuat();

    k = k.Hieu(m, n);
    cout << "Hiệu hai số phức là: ";
    k.Xuat();

    k = k.Tich(m, n);
    cout << "Tích hai số phức là: ";
    k.Xuat();

    k = k.Thuong(m, n);
    cout << "Thương hai số phức là: ";
    k.Xuat();

    return 0;
}