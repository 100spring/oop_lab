#include "Vector.h"

int main() {
    CVector v1, v2;
    cout << "Nhap vector thu nhat:\n";
    cin >> v1;

    cout << "Nhap vector thu hai:\n";
    cin >> v2;
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 . v2 = " << (v1 * v2) << endl;

    return 0;
}