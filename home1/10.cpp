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
    bool isCollinear(const Vector & tmp);
    Vector sum(const Vector & tmp);
    Vector mult(double k);
    Vector rotate(double deg_angle);
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

bool Vector::isCollinear(const Vector & tmp) {
    return this->cross(tmp) == 0;
}

Vector Vector::sum(const Vector & tmp) {
    this->x += tmp.x;
    this->y += tmp.y;
    return *this;
}

Vector Vector::mult(double k) {
    this->x *= k;
    this->y *= k;
    return *this;
}

Vector Vector::rotate(double deg_angle) {
    double rad_angle = M_PI / 180 * deg_angle;
    double cosa = cos(rad_angle);
    double sina = sin(rad_angle);
    double new_x = x*cosa + y*sina;
    double new_y = x*sina - y*cosa;
    x = new_x;
    y = new_y;
    return *this;
}

int main() {
    Vector v;
    v.scan();
    double angle;
    cin >> angle;
    v.rotate(angle).print();
    cout << endl;
    return 0;
}
