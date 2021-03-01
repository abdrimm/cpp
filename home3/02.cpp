#include <bits/stdc++.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Weapon {
    enum type {
        ATTACK,
        PROTECTION,
        NONE
    };
    type wtype;
    int value;
public:
    Weapon();
    Weapon(int value, string wtype);
    void print();
    bool operator>(const Weapon &);
    int getValue() const;
    int getType() const;
};

class Hero {
    string name;
    int attack;
    int protection;
    Weapon weap;
public:
    Hero(string name, int attack, int protection);
    void print();
    bool operator>(const Hero &);
    string getName() const;
    int getAttack() const;
    int getProtection() const;
    Weapon getWeapon() const;
    void setWeapon(const Weapon &);
};

Weapon::Weapon() {
    value = 0;
    wtype = NONE;
}

Weapon::Weapon(int value, string wtype) {
    this->value = value;
    if (wtype == "attack") {
        this->wtype = ATTACK;
    } else if (wtype == "protection") {
        this->wtype = PROTECTION;
    }
}

void Weapon::print() {
    cout << value << " " << wtype << endl;
}

bool Weapon::operator>(const Weapon & weap) {
    if (this->value > weap.value) {
        return true;
    } else {
        return false;
    }
}

int Weapon::getValue() const {
    return value;
}

int Weapon::getType() const {
    return wtype;
}



Hero::Hero(string name, int attack, int protection) {
    this->name = name;
    this->attack = attack;
    this->protection = protection;
    weap = Weapon();
}

void Hero::print() {
    cout << name << " " << attack << " " << protection << " ";
    weap.print();
}

bool Hero::operator>(const Hero & hero) {
    int attackPower = this->attack;
    if (this->weap.getType() == 0) {
        attackPower += this->weap.getValue();
    }
    int protPower = hero.protection;
    if (hero.weap.getType() == 1) {
        protPower += hero.weap.getValue();
    }
    if (attackPower > protPower) {
        return true;
    } else {
        return false;
    }
}

string Hero::getName() const {
    return name;
}

int Hero::getAttack() const {
    return attack;
}

int Hero::getProtection() const {
    return protection;
}

Weapon Hero::getWeapon() const {
    return weap;
}

void Hero::setWeapon(const Weapon & weap) {
    this->weap = weap;
}

int main() {
    int n, m;
    cin >> n;
    Hero **arr; 
    arr = new Hero*[n];
    for (int i = 0; i < n; i++) {
        string name;
        int attack, protection;
        cin >> name >> attack >> protection;
        arr[i] = new Hero(name, attack, protection);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string wname, hname;
        int value;
        cin >> value >> wname >> hname;
        Weapon weap(value, wname);
        for (int j = 0; j < n; j++) {
            if (hname == arr[j]->getName()) {
                if (weap.getValue() > arr[j]->getWeapon().getValue()) {
                    arr[j]->setWeapon(weap);           
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && *arr[i] > *arr[j]) {
                cout << arr[i]->getName() << " win " << arr[j]->getName() << endl;
            }
        }
    }
    delete arr;
    return 0;
}

