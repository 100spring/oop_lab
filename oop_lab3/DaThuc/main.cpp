#include "DaThuc.cpp"

int main(){
    DaThuc ds1, ds2, result;
    
    cout << "Nhập đa thức thứ nhất:" << endl;
    ds1.Nhap();
    
    cout << "Nhập đa thức thứ hai:" << endl;
    ds2.Nhap();

    cout << "Tính giá trị đa thức thứ nhất." << endl; 
    ds1.TinhGiaTri();

    cout << "Kết quả cộng hai đa thức là: " << endl;
    result = DaThuc::Cong(ds1, ds2);
    result.Xuat();
    
    cout << "Kết quả trừ đa thức thứ nhất cho đa thức thứ hai là: " << endl;
    result = DaThuc::Tru(ds1, ds2);
    result.Xuat();

    return 0;
}