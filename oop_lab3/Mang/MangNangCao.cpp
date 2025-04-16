#include "MangNangCao.h"

void AdvancedArray::LeNhoNhat() {
    int res = INT_MAX;
    bool check = false;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] % 2 == 1) {
            check = true;
            res = min(res, arr[i]);
        }
    }
    
    if(!check)
        cout << "Mảng không có phần tử lẻ." << endl;
    else 
        cout << "Phần tử lẻ nhỏ nhất trong mảng là: " << res << endl;
}

void AdvancedArray::SoNguyenToLonNhat() {
    int res = INT_MIN;
    bool check = false;
    
    for(int i = 0; i < arr.size(); i++) {
        if(SoNguyenTo(arr[i])) {
            check = true;
            res = max(res, arr[i]);
        }
    }
    
    if(!check)
        cout << "Mảng không có số nguyên tố." << endl;
    else
        cout << "Số nguyên tố lớn nhất trong mảng là: " << res << endl;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for(int i = 0; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

void AdvancedArray::SapXepGiamDan() {
    bubbleSort(arr);
}

void AdvancedArray::ThemPhanTu(int x) {
    arr.push_back(x);
    cout << "Đã thêm phần tử " << x << " vào mảng." << endl;
}

void AdvancedArray::TimKiemPhanTu(int x) {
    bool found = false;
    vector<int> positions;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == x) {
            found = true;
            positions.push_back(i);
        }
    }
    
    if(found) {
        cout << "Phần tử " << x << " được tìm thấy tại vị trí: ";
        for(int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    } else {
        cout << "Không tìm thấy phần tử " << x << " trong mảng." << endl;
    }
}