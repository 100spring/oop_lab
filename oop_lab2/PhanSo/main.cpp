#include "PhanSo.cpp"

int main(){
    phanSo f1, f2, f3;
    f1.Nhap();
    f2.Nhap();

    f1.SoSanh(f2);

    f3 = f3.Tong(f1, f2);
    cout << "Tổng hai phân số là: ";
    f3.Xuat();

    f3 = f3.Hieu(f1, f2);
    cout << "Hiệu hai phân số là: ";
    f3.Xuat();

    f3 = f3.Tich(f1, f2);
    cout << "Tích hai phân số là: ";
    f3.Xuat();

    f3 = f3.Thuong(f1, f2);
    cout << "Thương hai phân số là: ";
    f3.Xuat();

    return 0;
}