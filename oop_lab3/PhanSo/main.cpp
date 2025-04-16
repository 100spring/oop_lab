#include "MangPhanSo.cpp"

int main(){
    DSPhanSo ds;
    ds.Nhap();

    cout << "Tổng các phân số là: "; ds.Tong().Xuat();
    cout << endl;

    cout << "Phân số lớn nhất là: "; ds.PSLonNhat().Xuat();
    cout << endl;
    cout << "Phân số nhỏ nhất là: "; ds.PSNhoNhat().Xuat();
    cout << endl;

    cout << "Phân số có tử là số nguyên tố lớn nhất là(nếu không tìm thấy trả về 0/0): "; ds.NguyenToLonNhat().Xuat();
    cout << endl;

    cout << "Danh sách phân số khi sắp xếp tăng dần là: " << endl;
    ds.SXTangDan();
    ds.Xuat();

    cout << "Danh sách phân số khi sắp xếp giảm dần là: " << endl;
    ds.SXGiamDan();
    ds.Xuat();

    return 0;
}