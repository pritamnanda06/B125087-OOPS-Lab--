#include <iostream>
using namespace std;

class Bill {
public:
    int items;
    double total;
    Bill(int i = 0, double t = 0) { items = i; total = t; }
    Bill operator+(Bill b) { return Bill(items + b.items, total + b.total); }
    bool operator>(Bill b) { return total > b.total; }
};

int main() {
    int i1, i2;
    double t1, t2;
    cout << "Enter items and total of bill 1: ";
    cin >> i1 >> t1;
    cout << "Enter items and total of bill 2: ";
    cin >> i2 >> t2;

    Bill b1(i1, t1), b2(i2, t2), c = b1 + b2;
    cout << "Combined bill: " << c.items << " items, Rs. " << c.total << endl;
    cout << "Bill 1 > Bill 2 : " << (b1 > b2 ? "true" : "false") << endl;
}