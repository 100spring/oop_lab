#include "MaTran.h"

istream& operator>>(istream& in, CMatrix& m){
    cout << "Nhập số hàng: "; in >> m.rows;
    cout << "Nhập số cột: "; in >> m.cols;
    m.data.resize(m.rows, vector<double>(m.cols));
    cout << "Nhập các phần tử:\n";
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            in >> m.data[i][j];
        }
    return in;
}

ostream& operator<<(ostream& out, const CMatrix& m){
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            out << m.data[i][j] << "\t";
        }
        out << endl;
    }
    return out;
}

CMatrix CMatrix::operator+(const CMatrix& other){
    if (rows != other.rows || cols != other.cols)
        cout << "Kích thước không hợp lệ để cộng ma trận. \n";

    CMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

CMatrix CMatrix::operator-(const CMatrix& other){
    if (rows != other.rows || cols != other.cols)
        cout << "Kích thước không hợp lệ để trừ ma trận. \n";

    CMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

CMatrix CMatrix::operator*(const CMatrix& other){
    if (cols != other.rows)
        cout << "Kích thước không hợp lệ để nhân ma trận. \n";

    CMatrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}