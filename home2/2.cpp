#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

class Vector {
    double x, y, z;

public:
    Vector();
    Vector(double, double, double);

    Vector operator+(const Vector & v);
    Vector operator-(const Vector & v);

    friend std::istream& operator>>(std::istream & in, Vector & v);
    friend std::ostream& operator<<(std::ostream & out, const Vector & v);
};

Vector::Vector() {
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
}

Vector Vector::operator+(const Vector & v) {
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator-(const Vector & v) {
    return Vector(x - v.x, y - v.y, z - v.z);
}

std::istream& operator>>(std::istream & in, Vector & v) {
    in >> v.x >> v.y >> v.z;
    return in;
}

std::ostream& operator<<(std::ostream & out, const Vector & v) {
    out << setprecision(2) << fixed << '(' << v.x << "; " << v.y << "; " << v.z << ')';
    return out;
}

int main() {
    Vector v1, v2;
    cin >> v1 >> v2;
    cout << v1 + v2 << '\n' << v1 - v2 << endl;
    return 0;
}
