#include <iostream>
#include <vector>
using namespace std;

// hàm đếm số mảng con trong mảng lớn
// và tìm các vị trí xuất hiện mảng con
void findSubArray(vector<int>& A, vector<int>& B){
    vector<int> posArray; // mảng lưu vị trí mảng con
    int countSubArray = 0;
    
    for(int i = 0; i <= B.size()-A.size(); i++){
        bool correctSubArray = true;
        for(int j = 0; j < A.size(); j++){
            if(B[i+j] != A[j]){
                correctSubArray = false;
                break;
            }
        }
        if(correctSubArray){
            posArray.push_back(i); // thêm vị trí i vào mảng lưu vị trí
            countSubArray++;
        }
    }
    if(countSubArray > 0){
        cout << "So mang con tim duoc la: " << countSubArray << endl;
        cout << "Cac vi tri tim duoc mang con: ";
        for(int i = 0; i < posArray.size(); i++)
            cout << posArray[i] << " ";
    }
    else
        cout << "Khong tim thay mang con!";
}

int main(){
    int sizeA, sizeB;
    cout << "Lan luot nhap kich thuoc mang A va mang B:" << endl;
    cin >> sizeA >> sizeB;

    cout << "Nhap cac phan tu cua mang A:" << endl;
    vector<int> A(sizeA);
    for(int i = 0; i < sizeA; i++){
        cin >> A[i];
    }
    cout << "Nhap cac phan tu cua mang B:" << endl;
    vector<int> B(sizeB);
    for(int i = 0; i < sizeB; i++){
        cin >> B[i];
    }

    findSubArray(A, B);
    return 0;
}