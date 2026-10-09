#include <iostream>
using namespace std;

class Bill {
    int items;
    double total;
public:
    Bill(int i = 0, double t = 0) : items(i), total(t) {}
    void input(const char* name) {
        cout << "Enter number of items and total amount of " << name << ": ";
        cin >> items >> total;
    }
    Bill operator+(const Bill& o) const {
        return Bill(items + o.items, total + o.total);
    }
    bool operator>(const Bill& o) const { return total > o.total; }
    void display(const char* label) const {
        cout << label << "Items = " << items << ", Total = Rs. " << total << endl;
    }
};

int main() {
    Bill b1, b2;
    b1.input("Bill 1");
    b2.input("Bill 2");
    Bill combined = b1 + b2;
    cout << endl;
    b1.display("Bill 1    : ");
    b2.display("Bill 2    : ");
    combined.display("Combined  : ");
    cout << "\nBill 1 > Bill 2 : " << (b1 > b2 ? "true" : "false") << endl;
    return 0;
}