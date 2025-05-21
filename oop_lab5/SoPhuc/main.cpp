#include "SoPhuc.h"

int main(){
    SoPhuc a, b, res;
    cout << "Nhập vào hai số phức:" << endl;
    cin >> a >> b;

    cout << "So sánh hai số phức: ";
    if(a == b)
        cout << "Hai số phức bằng nhau" << endl;
    else 
        cout << "Hai số phức không bằng nhau" << endl;


    res = a + b;
    cout << "Tổng hai số phức: " << res << endl;

    res = a - b;
    cout << "Hiệu hai số phức: " << res << endl;

    res = a * b;
    cout << "Tích hai số phức: " << res << endl;

    res = a / b;
    cout << "Thương hai số phức: " << res << endl;

    return 0;
}