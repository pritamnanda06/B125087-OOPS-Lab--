#include <iostream>
using namespace std;

class Date {
public:
    int d, m, y;
    bool operator==(Date x) { return d == x.d && m == x.m && y == x.y; }
    bool operator!=(Date x) { return !(*this == x); }
};

int main() {
    Date a, b;
    cout << "Enter date 1 (dd mm yyyy): ";
    cin >> a.d >> a.m >> a.y;
    cout << "Enter date 2 (dd mm yyyy): ";
    cin >> b.d >> b.m >> b.y;

    cout << "Equal (==)     : " << (a == b ? "true" : "false") << endl;
    cout << "Not equal (!=) : " << (a != b ? "true" : "false") << endl;
}