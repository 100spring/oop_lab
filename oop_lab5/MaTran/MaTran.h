#include <iostream>
#include <vector>
using namespace std;

class CMatrix{
    private:
        vector<vector<double>> data;
        int rows, cols;
    public:
        CMatrix(int r, int c) {
            rows = r;
            cols = c;
            data.resize(r, vector<double>(c, 0));
        }
        friend istream& operator>>(istream& in, CMatrix& m);
        friend ostream& operator<<(ostream& out, const CMatrix& m);
        CMatrix operator+(const CMatrix& other);
        CMatrix operator-(const CMatrix& other);
        CMatrix operator*(const CMatrix& other);
};