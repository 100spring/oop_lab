#include "DaThuc.h"

int main() {
    DaThuc p1, p2;
    cout << "Nhap da thuc thu nhat:\n";
    cin >> p1;

    cout << "Nhap da thuc thu hai:\n";
    cin >> p2;

    DaThuc tong = p1 + p2;
    DaThuc hieu = p1 - p2;

    cout << "\nDa thuc thu nhat: " << p1 << endl;
    cout << "Da thuc thu hai: " << p2 << endl;
    cout << "Tong hai da thuc: " << tong << endl;
    cout << "Hieu hai da thuc: " << hieu << endl;

    return 0;
}