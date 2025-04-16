#include "MangNangCao.cpp"

int main(){
    AdvancedArray myArray;
    myArray.Nhap();
    cout << "Mảng có các phần tử lần lượt như sau: " << endl;
    myArray.Xuat();

    cout << myArray.DemGiaTri_x() << endl;

    myArray.KiemTraTangDan();

    myArray.LeNhoNhat();

    myArray.SoNguyenToLonNhat();

    myArray.SapXepGiamDan();
    cout << "Mảng sau khi sắp xếp giảm dần có dạng như sau: " << endl;
    myArray.Xuat();

    return 0;
}