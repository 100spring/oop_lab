#include <iostream>
using namespace std;

struct phanSo{
    int tuSo, mauSo;
};

// hàm tính ước chung lớn nhất, đầu vào là hai số nguyên
int ucln(int a, int b){
    while(a != b){
        if(a > b)
            a -= b;
        else 
            b -= a;
    }
    return a;
} 

int main(){
    phanSo f;
    cout << "Nhap phan so." << endl;
    // nhập phân số, nếu sai điều kiện yêu cầu nhập lại
    do{
        cout << "Nhap tu so: "; cin >> f.tuSo;
        cout << "Nhap mau so: "; cin >> f.mauSo;
        //kiểm tra điều kiện nhập
        if(f.mauSo == 0)
            cout << "Mau so khong duoc bang 0. Yeu cau nhap lai." << endl;
    }
    while(f.mauSo == 0);
    int k = ucln(f.tuSo, f.mauSo);
    cout << "Phan so sau khi rut gon la: " << f.tuSo/k << "/" << f.mauSo/k;
    return 0;
}