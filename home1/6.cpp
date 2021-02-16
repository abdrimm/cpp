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
    double dot(const Vector & tmp);
    double cross(const Vector & tmp);
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

double Vector::dot(const Vector & tmp) {
    return x*tmp.x + y*tmp.y;
}

double Vector::cross(const Vector & tmp) {
    return x*tmp.y - y*tmp.x;
}

int main() {
    Vector v1, v2;
    v1.scan();
    v2.scan();
    cout << setprecision(2) << fixed << v1.cross(v2) << endl;
    return 0;
}
