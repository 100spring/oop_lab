#include "NgayThangNam.cpp"
using namespace std;

int main(){
    ngayThangNam d;
    d.Nhap();
    d.NgayThangNamTiepTheo();
    cout << "Ngày tiếp theo của ngày này là: ";
    d.Xuat();
    return 0;
}