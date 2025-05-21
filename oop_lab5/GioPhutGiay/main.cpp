#include "GioPhutGiay.h"

int main() {
    CTime t1;
    cin >> t1;

    cout << "Thời gian ban đầu: " << t1 << endl;
    cout << "Sau khi cộng 70 giây: " << (t1 + 70) << endl;
    cout << "Sau khi trừ 130 giây: " << (t1 - 130) << endl;

    t1++;
    cout << "Sau hậu tố ++: " << t1 << endl;

    t1--;
    cout << "Sau hậu tố --: " << t1 << endl;

    return 0;
}