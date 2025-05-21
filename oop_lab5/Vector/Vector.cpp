#include "Vector.h"

istream& operator>>(istream& in, CVector& v){
    int n;
    cout << "Nhap so chieu vector: ";
    in >> n;
    v.data.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i << ": ";
        in >> v.data[i];
    }
    return in;
}

ostream& operator<<(ostream& out, CVector& v){
    out << "(";
    for (size_t i = 0; i < v.data.size(); ++i) {
        out << v.data[i];
        if (i != v.data.size() - 1) out << ", ";
    }
    out << ")";
    return out;
}

CVector CVector::operator+(CVector& other){
    if (data.size() != other.data.size()) {
        cout << "Kích thước vector không hợp lệ khi cộng." << endl;
    }
    CVector res(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        res.data[i] = data[i] + other.data[i];
    }
    return res;
}

CVector CVector::operator-(CVector& other){
    if (data.size() != other.data.size()) {
        cout << "Kích thước vector không hợp lệ khi trừ." << endl;
    }
    CVector res(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        res.data[i] = data[i] - other.data[i];
    }
    return res;
}

double CVector::operator*(CVector& other){
    if (data.size() != other.data.size()) {
        cout << "Kích thước vector không hợp lệ khi lấy tích vô hướng." << endl;
    }
    double sum = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i] * other.data[i];
    }
    return sum;
}