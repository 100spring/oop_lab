#include <bits/stdc++.h>
using namespace std;

class BasicArray {
protected:
    vector<int> arr;
public:
    void Nhap();
    void Xuat();
    int DemGiaTri_x();
    void KiemTraTangDan();    
    vector<int>& getArray(){
        return arr;
    }
};