#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = (numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero fraction");
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        if (frac.denominator == 1) {
            os << frac.numerator;
        }
        else {
            os << frac.numerator << "/" << frac.denominator;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& frac) {
        char separator; 
        is >> frac.numerator >> separator >> frac.denominator;
        if (frac.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        frac.simplify();
        return is;
    }
};

int main() {
    try {
        Fraction a(3, 4);
        Fraction b(2, 5);

        cout << "a = " << a << "\n";
        cout << "b = " << b << "\n";

        cout << "a + b = " << a + b << "\n";
        cout << "a - b = " << a - b << "\n";
        cout << "a * b = " << a * b << "\n";
        cout << "a / b = " << a / b << "\n";

        Fraction c;
        cout << "Enter a fraction (format a/b): ";
        cin >> c;
        cout << "You entered: " << c << "\n";
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

}
