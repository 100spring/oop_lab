#include <iostream>
using namespace std;

class CTime{
    private:
        int hrs, min, sec;
    public:
        friend istream& operator>>(istream& in, CTime& t);
        friend ostream& operator<<(ostream& out, CTime& t);
        CTime ChuanHoa(CTime t);
        CTime operator+(int a);
        CTime operator-(int a);
        CTime operator++(int);
        CTime operator--(int);
};