#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class CVector{
    private:
        vector<double> data;
    public:
        CVector(int n = 0) {
            data.resize(n, 0);
        }
        friend istream& operator>>(istream& in, CVector& v);
        friend ostream& operator<<(ostream& out, CVector& v);
        CVector operator+(CVector& other);
        CVector operator-(CVector& other);
        double operator*(CVector& other);
};