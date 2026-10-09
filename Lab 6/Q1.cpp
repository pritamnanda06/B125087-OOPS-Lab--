#include <iostream>
using namespace std;

class Fraction {
public:
    int num, den;
    Fraction(int n = 0, int d = 1) { num = n; den = d; simplify(); }

    void simplify() {                       // helper function
        if (den < 0) { num = -num; den = -den; }
        int a = num < 0 ? -num : num, b = den;
        while (b) { int t = a % b; a = b; b = t; }
        if (a > 1) { num /= a; den /= a; }
    }
    Fraction operator+(Fraction f) { return Fraction(num * f.den + f.num * den, den * f.den); }
    Fraction operator-(Fraction f) { return Fraction(num * f.den - f.num * den, den * f.den); }
};

int main() {
    int a, b, c, d;
    cout << "Enter numerator and denominator of fraction 1: ";
    cin >> a >> b;
    cout << "Enter numerator and denominator of fraction 2: ";
    cin >> c >> d;
    if (b == 0 || d == 0) { cout << "Denominator cannot be zero.\n"; return 0; }

    Fraction f1(a, b), f2(c, d);
    Fraction sum = f1 + f2, diff = f1 - f2;
    cout << "Sum        = " << sum.num << "/" << sum.den << endl;
    cout << "Difference = " << diff.num << "/" << diff.den << endl;
}