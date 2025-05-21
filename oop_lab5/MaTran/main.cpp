#include "MaTran.h"

int main(){
    CMatrix A, B;
    cout << "Nhap ma tran A:" << endl;
    cin >> A;

    cout << "Nhap ma tran B:" << endl;
    cin >> B;

    cout << "A + B =" << endl << (A + B);
    cout << "A - B =" << endl << (A - B);
    cout << "A * B =" << endl << (A * B);

    return 0;
}