#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction {
    int num, den;
    static int gcd(int a, int b) {
        a = abs(a); b = abs(b);
        while (b) { int t = a % b; a = b; b = t; }
        return a;
    }
    // helper: simplify using GCD and keep denominator positive
    void simplify() {
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(num, den);
        if (g > 1) { num /= g; den /= g; }
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { simplify(); }
    Fraction operator+(const Fraction& o) const {
        return Fraction(num * o.den + o.num * den, den * o.den);
    }
    Fraction operator-(const Fraction& o) const {
        return Fraction(num * o.den - o.num * den, den * o.den);
    }
    void display() const {
        if (den == 1) cout << num; else cout << num << "/" << den;
    }
};

Fraction readFraction(const char* name) {
    int n, d;
    do {
        cout << "Enter numerator and denominator of " << name << ": ";
        cin >> n >> d;
        if (d == 0) cout << "Denominator cannot be zero. Try again.\n";
    } while (d == 0);
    return Fraction(n, d);
}

int main() {
    Fraction f1 = readFraction("Fraction 1");
    Fraction f2 = readFraction("Fraction 2");
    Fraction sum = f1 + f2, diff = f1 - f2;
    cout << "\nFraction 1 = "; f1.display();
    cout << "\nFraction 2 = "; f2.display();
    cout << "\nSum        = "; sum.display();
    cout << "\nDifference = "; diff.display();
    cout << endl;
    return 0;
}