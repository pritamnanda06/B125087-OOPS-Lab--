#include <iostream>
using namespace std;

class InventoryItem {
public:
    int id, qty;
    double price;
    InventoryItem(int i = 0, double p = 0, int q = 0) { id = i; price = p; qty = q; }

    // combines only if product ID and unit price match
    InventoryItem operator+(InventoryItem x) {
        if (id == x.id && price == x.price)
            return InventoryItem(id, price, qty + x.qty);
        cout << "Incompatible items (ID or unit price differs). Cannot combine.\n";
        return InventoryItem();            // empty item; originals untouched
    }
};

int main() {
    int i1, q1, i2, q2;
    double p1, p2;
    cout << "Enter ID, unit price, quantity of item 1: ";
    cin >> i1 >> p1 >> q1;
    cout << "Enter ID, unit price, quantity of item 2: ";
    cin >> i2 >> p2 >> q2;

    InventoryItem a(i1, p1, q1), b(i2, p2, q2);
    InventoryItem c = a + b;
    if (c.id != 0 || c.qty != 0)
        cout << "Combined item -> ID: " << c.id << ", Price: " << c.price
             << ", Quantity: " << c.qty << endl;
}