#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

class NhanVien{
    protected:
        string ma, ten, ngaysinh;
        double luong;
    public:
        NhanVien();
        ~NhanVien();
        void Nhap();
        void Xuat();
        double getLuong();
        int getTuoi();  
};