#include <iostream>
#include <cmath>
using namespace std;

// hàm nhập vào một giá trị x đơn vị radian,
// trả về kết quả sin(x) theo công thức khai triển 
double sineCalculate(double x) {
    double sum = x;
    double temp = x;
    int i = 1;
    while(fabs(temp) >= 0.00001) {
        // lặp đến khi giá trị của temp nhỏ hơn hơn độ chính xác yêu cầu 
        temp *= -(x*x)/((2*i) * (2*i+1)); 
        sum += temp;
        i++;
    }
    return sum;
}
int main() {
    double x;
    cout << "Nhap gia tri goc x(radian): ";
    cin >> x;
    cout << "Gia tri sin(x) la: " << sineCalculate(x) << endl;
    return 0;
}