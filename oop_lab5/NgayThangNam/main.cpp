#include "NgayThangNam.h"

int main() {
    CDate d1(1, 1, 2024);
    CDate d2;

    cout << "Nhap ngay d2 (d/m/y): ";
    cin >> d2;

    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;

    cout << "d1 + 5 ngay: " << d1 + 5 << endl;
    cout << "d2 - 3 ngay: " << d2 - 3 << endl;

    cout << "Khoang cach giua d2 va d1: " << d2 - d1 << " ngay\n";

    ++d1;
    cout << "d1 sau ++: " << d1 << endl;

    d2--;
    cout << "d2 sau --: " << d2 << endl;

    return 0;
}