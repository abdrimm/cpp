#include <bits/stdc++.h>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Good {
    const int id;
    const string name;
    const int price;
    int number;
    friend class Catalog;
    Good(int nId, string nName, int nPrice, int number)
        : id(nId), name(nName), price(nPrice) 
    {
        this->number = number;
    }
};

class Catalog {
    int numberOfGoods;
    Good **list;
public:
    Catalog(int n);
    ~Catalog();
    void buy(string name, int number);
    void buy(int id, int number);
    void print() const;
};

Catalog::Catalog(int n) {
    string name;
    int price, number;
    char ch;
    numberOfGoods = 0;
    list = new Good* [n];
    for (int i = 0; i < n; i++) {
        cin >> ch >> name >> price >> number;
        Good *tmp = new Good(numberOfGoods, name, price, number);
        numberOfGoods++;
        list[i] = tmp;
    }
}

Catalog::~Catalog() {
    for (int i = 0; i < numberOfGoods; i++) {
        delete list[i];
    }
    delete [] list;
}

void Catalog::buy(string name, int number) {
    for (int i = 0; i < numberOfGoods; i++) {
        if (list[i]->name == name) {
            if (number <= list[i]->number) {
                list[i]->number -= number; 
                cout << list[i]->name << " x " << number << " = " << number * list[i]->price << endl; 
                return;
            } else if (list[i]->number < number) {
                cout << list[i]->name << " x " << number << " = not enough" << endl; 
                return;
            }
        }
    }
    cout << name << " = incorrect name" << endl; 
}

void Catalog::buy(int id, int number) {
    for (int i = 0; i < numberOfGoods; i++) {
        if (list[i]->id == id) { 
            if (number <= list[i]->number) {
                list[i]->number -= number; 
                cout << list[i]->name << " x " << number << " = " << number * list[i]->price << endl; 
                return;
            } else if (list[i]->number < number) {
                cout << list[i]->name << " x " << number << " = not enough" << endl; 
                return;
            }
        }
    }
    cout << id << " = incorrect index" << endl; 
}

void Catalog::print() const {
    cout << "# name price number" << endl;
    for (int i = 0; i < numberOfGoods; i++) {
        cout << list[i]->id << " " << list[i]->name << " " << 
        list[i]->price << " " << list[i]->number << endl;
    }
}

int main() {
    int n, m;
    char ch;
    cin >> n;
    Catalog catalog(n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> ch;
        if (ch == '?') {
            string name;
            int number;
            cin >> name >> number;
            catalog.buy(name, number);
        } else if (ch == '#') {
            int id;
            int number;
            cin >> id >> number;
            catalog.buy(id, number);
        }
    }

    catalog.print();
    return 0;
}

