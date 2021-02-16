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
    int quadrant();
    void normalize();
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

int Vector::quadrant() {
    int q = 0;
    if (x > 0) {
        if (y > 0) 
            q = 1;
        else if (y < 0)
            q = 4; 
    } else if (x < 0) {
        if (y > 0) 
            q = 2;
        else if (y < 0)
            q = 3;
    }
    return q;
}

void Vector::normalize() {
    double len = this->len();
    x /= len;
    y /= len;
}

int main() {
    Vector v;
    v.scan();
    v.normalize();
    v.print();
    cout << endl;
    return 0;
}
