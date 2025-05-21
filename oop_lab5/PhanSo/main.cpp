#include "PhanSo.h"

int main(){
    PhanSo a, b, res;
    cout << "Nhập vào hai phân số:" << endl;
    cin >> a >> b;

    cout << "So sánh hai phân số: ";
    if(a == b)
        cout << "Hai phân số bằng nhau" << endl;
    else if(a < b)
        cout << "Phân số thứ nhất nhỏ hơn" << endl;
    else 
        cout << "Phân số thứ nhất lớn hơn" << endl;

    res = a + b;
    cout << "Tổng hai phân số: " << res << endl;

    res = a - b;
    cout << "Hiệu hai phân số: " << res << endl;

    res = a * b;
    cout << "Tích hai phân số: " << res << endl;

    res = a / b;
    cout << "Thương hai phân số: " << res << endl;

    return 0;
}