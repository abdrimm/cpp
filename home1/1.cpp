#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::setw;
using std::setfill;
using std::fixed;

struct Vector {
    double x, y;
    
    void scan();
    void print();
};

void Vector::scan() {
    cin >> x >> y;
}

void Vector::print() {
    cout << setprecision(2) << fixed << '(' << x << "; " << y << ')';
}

int main() {
    Vector v;
    v.scan();
    v.print();
    cout << endl;
    return 0;
}
