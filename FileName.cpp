#include <iostream>
using namespace std;

class Fraction {
private:
    int numer;
    int divider; 

public:
    
    Fraction(int numer = 0, int divider = 1) {
        if (divider == 0) {
            cout << "can't be zero" << endl;
            divider = 1;
        }
        this->numer = numer;
        this->divider = divider;
    }

   
    void read() {
        cin >> numer >> divider;
        if (divider == 0) {
            cout << "can't be zero" << endl;
            divider = 1;
        }
    }

    
    void print() const {
        if (divider == 1) {
            cout << numer;
        }
        else {
            cout << numer << "/" << divider;
        }
    }

    
    Fraction sumWith(const Fraction& other) const {
        int newNumer = this->numer * other.divider + other.numer * this->divider;
        int newDivider = this->divider * other.divider;
        return Fraction(newNumer, newDivider);
    }

    
    Fraction diffWith(const Fraction& other) const {
        int newNumer = this->numer * other.divider - other.numer * this->divider;
        int newDivider = this->divider * other.divider;
        return Fraction(newNumer, newDivider);
    }

    
    Fraction prodWith(const Fraction& other) const {
        int newNumer = this->numer * other.numer;
        int newDivider = this->divider * other.divider;
        return Fraction(newNumer, newDivider);
    }

    
    Fraction quotWith(const Fraction& other) const {
        if (other.numer == 0) {
            cout << "Division isn't allowed" << endl;
            return Fraction(0, 1);
        }
        int newNumer = this->numer * other.divider;
        int newDivider = this->divider * other.numer;
        return Fraction(newNumer, newDivider);
    }
};

int main() {
    Fraction f1, f2;
    cout << "(numerator and divider): ";
    f1.read();
    cout << "(numerator and divider): ";
    f2.read();

    cout << "Sum: ";
    Fraction sum = f1.sumWith(f2);
    sum.print();
    cout << "\n";

    cout << "Difference: ";
    Fraction diff = f1.diffWith(f2);
    diff.print();
    cout << "\n";

    cout << "Product: ";
    Fraction prod = f1.prodWith(f2);
    prod.print();
    cout << "\n";

    cout << "Quotient: ";
    Fraction quot = f1.quotWith(f2);
    quot.print();
    cout << "\n";

    return 0;
}
