#include "TamGiac.cpp"

int main(){
    TamGiac h;
    h.Nhap();

    h.KiemTraLoai();

    cout << "Chu vi tam giác là: " << h.ChuVi() << endl;
    cout << "Diện tích tam giác là: " << h.DienTich() << endl;

    h.TinhTien();
    h.Xuat();

    h.PhongTo();
    h.Xuat();
    
    h.Quay();
    h.Xuat();

    return 0;
}