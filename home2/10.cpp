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
    Vector operator*(double);
    double operator[](char) const;

    friend std::istream& operator>>(std::istream & in, Vector & v);
    friend std::ostream& operator<<(std::ostream & out, const Vector & v);
};

class Matrix {
    double m[3][3];

public:
    Matrix(double);
    Matrix(double a[3][3]);

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Vector operator*(const Vector&);

    friend std::istream& operator>>(std::istream & in, Matrix&);
    friend std::ostream& operator<<(std::ostream & out, const Matrix&);
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

Vector Vector::operator*(double k) {
    return Vector(x * k, y * k, z * k);
}

double Vector::operator[](char ch) const {
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

Matrix::Matrix(double k = 1) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (i == j)
                m[i][j] = k;
            else
                m[i][j] = 0;
        }
}

Matrix::Matrix(double a[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] = a[i][j];
}

Matrix Matrix::operator+(const Matrix & B) {
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++)
            m[i][j] += B.m[i][j];
    return *this;
}

Matrix Matrix::operator-(const Matrix & B) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] -= B.m[i][j];
    return *this;
}

Matrix Matrix::operator*(const Matrix & B) {
    Matrix C(0.);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                C.m[i][j] += m[i][k] * B.m[k][j];
    return C;
}

Vector Matrix::operator*(const Vector & v) {
    Vector result;
    for (int j = 0; j < 3; j++) {
        Vector tmp(m[0][j], m[1][j], m[2][j]);
        result = result + tmp * v['x' + j];
    }
    return result;    
}

std::istream& operator>>(std::istream & in, Matrix & A) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            in >> A.m[i][j];
    return in;
}

std::ostream& operator<<(std::ostream & out, const Matrix & A) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
            out << setprecision(2) << fixed << A.m[i][j] << ' ';
        out << endl;        
    }
    return out;
}

int main() {
    Matrix A;
    Vector b;
    cin >> A >> b;
    cout << A * b << endl;
    return 0;
}
