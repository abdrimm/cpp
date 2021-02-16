#include <iostream>
#include <iomanip>
#include <cmath>

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
    double len();
};

void Vector::scan() {
    cin >> x >> y;
}

void Vector::print() {
    cout << setprecision(2) << fixed << '(' << x << "; " << y << ')';
}

double Vector::len() {
    return sqrt(x*x + y*y);
}

int main() {
    Vector v;
    v.scan();
    cout << setprecision(2) << fixed << v.len() << endl;
    return 0;
}
