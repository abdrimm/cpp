#include <bits/stdc++.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Quad {
public:
    int i1, i2, i3, i4;
    Quad();
    Quad(int i1, int i2, int i3, int i4);
    static bool is(int, int, int, int);
    virtual void print();
};

void Quad::print() {
    cout << "Quad: " << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
}

Quad::Quad() {
    i1 = i2 = i3 = i4 = 0;
}

Quad::Quad(int i1, int i2, int i3, int i4) {
    this->i1 = i1;
    this->i2 = i2;
    this->i3 = i3;
    this->i4 = i4;
}

bool Quad::is(int i1, int i2, int i3, int i4) {
    return true;
}

class Parallelogram: public Quad {
public:
    Parallelogram();
    Parallelogram(int i1, int i2, int i3, int i4);
    static bool is(int, int, int, int);
    virtual void print();
};

void Parallelogram::print() {
    cout << "Parallelogram: " << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
}

Parallelogram::Parallelogram() {
    i1 = i2 = i3 = i4 = 0;
}

Parallelogram::Parallelogram(int i1, int i2, int i3, int i4) {
    this->i1 = i1;
    this->i2 = i2;
    this->i3 = i3;
    this->i4 = i4;
}

bool Parallelogram::is(int i1, int i2, int i3, int i4) {
    if (i2 == i4 && i1 == i3) {
        return true;
    } else {
        return false;
    }
}

class Square: public Parallelogram{
public:
    Square(int, int, int, int);
    static bool is(int, int, int, int);
    virtual void print();
};

void Square::print() {
    cout << "Square: " << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
}

Square::Square(int i1, int i2, int i3, int i4) {
    this->i1 = i1;
    this->i2 = i2;
    this->i3 = i3;
    this->i4 = i4;
}

bool Square::is(int i1, int i2, int i3, int i4) {
    if (i2 == i4 && i1 == i3 && i1 == i2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    Quad **arr = new Quad*[n];
    for (int i = 0; i < n; i++) {
        Quad *ptr;
        int i1, i2, i3, i4;
        cin >> i1 >> i2 >> i3 >> i4;
        if (Square::is(i1, i2, i3, i4)) {
            ptr = new Square(i1, i2, i3, i4); 
        } else if (Parallelogram::is(i1, i2, i3, i4)) {
            ptr = new Parallelogram(i1, i2, i3, i4);
        } else {
            ptr = new Quad(i1, i2, i3, i4);
        }
        ptr->print();
        arr[i] = ptr;
    }

    for (int i = 0; i < n; i++) {
        delete arr[i];
    }
    delete [] arr;
    return 0;
}

