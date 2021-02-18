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
    int args;
    cin >> args;
    if (args == 0) {
        Matrix A;
        cout << A;
    } else if (args == 1) {
        double k;
        cin >> k;
        Matrix B(k);
        cout << B;
    } else if (args == 9) {
        double a[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
        Matrix C(a);
        cout << C;
    }
    return 0;
}
