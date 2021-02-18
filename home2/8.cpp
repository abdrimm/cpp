#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

class Matrix {
    double m[3][3];

public:
    Matrix(double);
    Matrix(double a[3][3]);

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);

    friend std::istream& operator>>(std::istream & in, Matrix&);
    friend std::ostream& operator<<(std::ostream & out, const Matrix&);
};

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

Matrix Matrix::operator+(const Matrix & A) {
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++)
            m[i][j] += A.m[i][j];
    return *this;
}

Matrix Matrix::operator-(const Matrix & A) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] -= A.m[i][j];
    return *this;
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
    Matrix A, B;
    cin >> A >> B;
    cout << A + B;
    return 0;
}
