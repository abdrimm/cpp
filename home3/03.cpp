#include <bits/stdc++.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int gcd(int a, int b) {
    int c;
    while (b) {
      c = a % b;
      a = b;
      b = c;        
    }
    return abs(a);
}

int lcm(int a, int b) {
    int d = gcd(a, b);
    return (a * b) / d;
}

class Pair {
protected:
    int left, right;
public:
    Pair();
    Pair(int left, int right);
};

Pair::Pair() {
    left = right = 0;
}

Pair::Pair(int left, int right) {
    this->left = left;
    this->right = right;
}

class Rational: public Pair {
public:
    Rational();
    Rational(int left, int right);
    void normalize();
    Rational operator+(const Rational &);
    Rational operator-(const Rational &);
    Rational operator*(const Rational &);
    void print();
};

Rational::Rational() {
    left = 0;
    right = 1;
}

Rational::Rational(int left, int right) {
    this->left = left;
    this->right = right;
    this->normalize();
}

void Rational::normalize() {
    int d = gcd(left, right);
    this->left /= d;
    this->right /= d;
}

Rational Rational::operator+(const Rational & q) {
    int down = lcm(this->right, q.right);
    int up = this->left * (down / this->right) + q.left * (down / q.right);
    Rational res(up, down);
    res.normalize();
    return res;
}

Rational Rational::operator-(const Rational & q) {
    int down = lcm(this->right, q.right);
    int up = this->left * (down / this->right) - q.left * (down / q.right);
    Rational res(up, down);
    res.normalize();
    return res;
}

Rational Rational::operator*(const Rational & q) {
    int down = this->right *q.right;
    int up = this->left * q.left;
    Rational res(up, down);
    res.normalize();
    return res;
}

void Rational::print() {
    cout << this->left << "/" << this->right << endl;
}

class Complex: public Pair {
public:
    Complex();
    Complex(int left, int right);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    Complex operator*(const Complex &);
    void print();
};

Complex::Complex() {
    left = 0;
    right = 1;
}

Complex::Complex(int left, int right) {
    this->left = left;
    this->right = right;
}

Complex Complex::operator+(const Complex & q) {
    Complex res(this->left + q.left, this->right + q.right);
    return res;
}

Complex Complex::operator-(const Complex & q) {
    Complex res(this->left - q.left, this->right - q.right);
    return res;
}

Complex Complex::operator*(const Complex & q) {
    Complex res(this->left * q.left - this->right * q.right, this->left * q.right + this->right * q.left);
    return res;
}

void Complex::print() {
    cout << this->left << " + i(" << this->right << ")\n";
}

int main() {
    Rational rat;
    Complex com;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int type;
        char op;
        int i1, i2;
        cin >> type >> op >> i1 >> i2;
        if (type == 1) {
            Rational tmp(i1, i2);
            switch(op) {
            case '+':
                rat = rat + tmp;
                break;
            case '-':
                rat = rat - tmp;
                break;
            case '*':
                rat = rat * tmp;
                break;
            }
            rat.print();
        } else if (type == 2) {
            Complex tmp(i1, i2);
            switch(op) {
            case '+':
                com = com + tmp;
                break;
            case '-':
                com = com - tmp;
                break;
            case '*':
                com = com * tmp;
                break;
            }
            com.print();
        }
    }
    return 0;
}

