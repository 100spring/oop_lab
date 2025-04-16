#include "DaGiac.cpp"

int main(){
    DaGiac k;
    k.Nhap();

    cout << "Chu vi đa giác là: " << k.ChuVi() << endl;

    cout << "Diện tích đa giác là: " << k.DienTich() << endl;

    k.TinhTien();
    k.Xuat();

    k.PhongTo();
    k.Xuat();

    k.Quay();
    k.Xuat();
}