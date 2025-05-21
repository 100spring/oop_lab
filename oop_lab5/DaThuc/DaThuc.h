#include <iostream>
#include <vector>
using namespace std;

class DaThuc{
    private:
        vector<double> heso;
    public:
        friend istream& operator>>(istream& in, DaThuc& dt);
        friend ostream& operator<<(ostream& out, DaThuc& dt);
        DaThuc operator+(DaThuc& other);
        DaThuc operator-(DaThuc& other);

};