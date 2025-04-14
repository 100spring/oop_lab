#include "PhanSo.h"

// nếu phân số là số âm, hàm đưa phân số về dạng
// chuẩn hóa, mẫu số là số dương
void chuanHoa(int& Tu, int& Mau){
    if(Mau < 0){
        Tu = - Tu;
        Mau = - Mau;
    }
}

// hàm tính ước chung lớn nhất của hai số
int ucln(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void phanSo::Nhap(){
    do{
        cout << "Nhập phân số." << endl;
        cout << "Tử số: "; cin >> iTu;
        cout << "Mẫu số: "; cin >> iMau;
        if(iMau == 0)
            cout << "Mẫu số phải khác 0. Vui lòng nhập lại." << endl;
    }
    while(iMau == 0);
}

void phanSo::Xuat(){
    chuanHoa(iTu, iMau);
    cout << iTu << "/" << iMau << endl;
}

// rút gọn bằng cách chia tử và mẫu cho ước chung lớn nhất của tử và mẫu
void phanSo::RutGon(){
    int d = ucln(iTu, iMau);
    iTu /= d;
    iMau /= d;
}

phanSo phanSo::Tong(phanSo a, phanSo b){
    phanSo temp;
    // quy đồng mẫu số
    temp.iTu = a.iTu*b.iMau + b.iTu*a.iMau;
    temp.iMau = a.iMau*b.iMau;
    temp.RutGon();
    return temp;
}

phanSo phanSo::Hieu(phanSo a, phanSo b){
    phanSo temp;
    // quy đồng mẫu số
    temp.iTu = a.iTu*b.iMau - b.iTu*a.iMau;
    temp.iMau = a.iMau*b.iMau;
    temp.RutGon();
    return temp;
}

phanSo phanSo::Tich(phanSo a, phanSo b){
    phanSo temp;
    temp.iTu = a.iTu*b.iTu;
    temp.iMau = a.iMau*b.iMau;
    temp.RutGon();
    return temp;
}

phanSo phanSo::Thuong(phanSo a, phanSo b){
    phanSo temp;
    // nhân nghịch đảo
    temp.iTu = a.iTu*b.iMau;
    temp.iMau = a.iMau*b.iTu;
    temp.RutGon();
    return temp;
}

// so sánh hai phân số bằng cách kiểm tra hiệu hai tử số sau khi quy đồng
void phanSo::SoSanh(phanSo a){
    // hiệu âm
    if(iTu*a.iMau - a.iTu*iMau > 0)
        cout << "Phân số thứ nhất lớn hơn phân số thứ hai." << endl;
    // hiệu dương
    else if(iTu*a.iMau - a.iTu*iMau < 0)
        cout << "Phấn số thứ nhất nhỏ hơn phân số thứ hai." << endl;
    // hiệu bằng 0
    else 
        cout << "Hai phân số bằng nhau." << endl;
}