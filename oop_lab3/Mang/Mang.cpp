#include "Mang.h"

void BasicArray::Nhap() {
    int n;
    cout << "Số phần tử của mảng: "; 
    cin >> n;
    arr.resize(n);
    
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void BasicArray::Xuat() {
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int BasicArray::DemGiaTri_x() {
    int k;
    cout << "Giá trị muốn tìm trong mảng: "; 
    cin >> k;
    
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == k)
            count++;
    }
    cout << "Số lần tìm thấy giá trị " << k << " trong mảng là: ";
    return count;
}

void BasicArray::KiemTraTangDan() {
    bool tangDan = true;
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[i-1]) {
            tangDan = false;
            break;
        }
    }
    
    if(tangDan)
        cout << "Mảng được sắp xếp tăng dần." << endl;
    else 
        cout << "Mảng không được sắp xếp tăng dần." << endl;
}

bool SoNguyenTo(int n) {
    if(n <= 1) 
        return false;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) 
            return false;
    }
    return true;
}