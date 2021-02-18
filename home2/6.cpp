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

    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    Vector operator*(double);
    Vector operator/(double);
    Vector operator*(const Vector&);
    double operator[](char);

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

Vector Vector::operator*(double k) {
    return Vector(x * k, y * k, z * k);
}

Vector Vector::operator/(double k) {
    if (k != 0)
        return Vector(x / k, y / k, z / k);
    else {
        cout << "Error: division by zero" << endl;
        return Vector(x, y, z);
    }
}

Vector Vector::operator*(const Vector & v) {
    return Vector(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

double Vector::operator[](char ch) {
    if (ch == 'x')
        return x;
    else if (ch == 'y')
        return y;
    else if (ch == 'z')
        return z;
    else
        throw "Error: incorrect index";
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
    Vector v;
    char ch;
    cin >> v >> ch;
    try {
        cout << setprecision(2) << fixed << v[ch] << endl; 
    } catch (const char *msg) {
        cout << msg << endl;
    }
    return 0;
}
