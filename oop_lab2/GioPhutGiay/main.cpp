#include "GioPhutGiay.cpp"

int main(){
    gioPhutGiay m;
    m.Nhap();

    m.TinhCongThemMotGiay();

    cout << "Sau khi cộng thêm một giây, thời điểm hiện tại là ";
    m.Xuat();

    return 0;
}