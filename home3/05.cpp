#include <bits/stdc++.h>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Computer {
protected:
    int cr;
    int ram;
public:
    Computer();
    Computer(int cr, int ram);
    int getCr();
    int getRam();
    virtual void print();
};

Computer::Computer() {
    cr = ram = 0;
}

Computer::Computer(int cr, int ram) {
    this->cr = cr;
    this->ram = ram;
}

int Computer::getCr() {
    return cr;
}

int Computer::getRam() {
    return ram;
}

void Computer::print() {
    cout << "Computer " << cr << " GHz " << ram << " Mb" << endl;
}

class Notebook: public Computer {
private:
    string vendor;
    int battery;
public:
    Notebook();
    Notebook(int cr, int ram, int battery, string vendor);
    //int getCr();
    //int getRam();
    void print();
};

Notebook::Notebook() {
    cr = 0;
    ram = 0;
    battery = 0;
    vendor = "none";
}

Notebook::Notebook(int cr, int ram, int battery, string vendor) {
    this->cr = cr;
    this->ram = ram;
    this->battery = battery;
    this->vendor = vendor;
}

/*int Notebook::getCr() {
    return cr;
}

int Notebook::getRam() {
    return ram;
}*/

void Notebook::print() {
    cout << "Notebook " << cr << " GHz " << ram << " Mb " << battery << " hour " << vendor << endl;
}

class Monoblock: public Computer {
    int display;
public:
    Monoblock();
    Monoblock(int cr, int ram, int display);
    void print();
};

Monoblock::Monoblock() {
    cr = ram = display = 0;
}

Monoblock::Monoblock(int cr, int ram, int display) {
    this->cr = cr;
    this->ram = ram;
    this->display = display;
}

void Monoblock::print() {
    cout << "Monoblock " << cr << " GHz " << ram << " Mb " << display << '"' << endl;
}

int main() {
    int n;
    int maxCr = 0, maxRam = 0;
    cin >> n;
    Computer **arr = new Computer*[n];
    for (int i = 0; i < n; i++) {
        int cr, ram;
        int battery;
        string vendor;
        int display;
        char ch;

        cin >> ch;

        switch (ch) {
        case '?':
            cin >> cr >> ram;
            arr[i] = new Computer(cr, ram);
            break;
        case 'N':
            cin >> cr >> ram >> battery >> vendor;
            arr[i] = new Notebook(cr, ram, battery, vendor);
            break;
        case 'M':
            cin >> cr >> ram >> display;
            arr[i] = new Monoblock(cr, ram, display);
            break;
        }

        if (arr[i]->getCr() > maxCr) {
            maxCr = arr[i]->getCr();
        }

        if (arr[i]->getRam() > maxRam) {
            maxRam = arr[i]->getRam();
        }
    }

    cout << "Maximum clockRate:" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i]->getCr() == maxCr) {
            arr[i]->print();
        }
    }

    cout << "Maximum RAM:" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i]->getRam() == maxRam) {
            arr[i]->print();
        }
        delete arr[i];
    }
    delete [] arr;
    return 0;
}

