#include <iostream>
using namespace std;

class InventoryItem {
    int id;
    double price;
    int qty;
public:
    InventoryItem(int i = 0, double p = 0, int q = 0) : id(i), price(p), qty(q) {}
    void input(const char* name) {
        cout << "Enter product ID, unit price and quantity of " << name << ": ";
        cin >> id >> price >> qty;
    }
    bool compatible(const InventoryItem& o) const {
        return id == o.id && price == o.price;
    }
    // Returns combined item if compatible; otherwise returns a default item
    // (qty 0, id 0). Use compatible() to check beforehand.
    InventoryItem operator+(const InventoryItem& o) const {
        if (compatible(o)) return InventoryItem(id, price, qty + o.qty);
        return InventoryItem();
    }
    void display() const {
        cout << "ID: " << id << ", Unit Price: " << price << ", Quantity: " << qty;
    }
};

int main() {
    InventoryItem a, b;
    a.input("Item 1");
    b.input("Item 2");
    cout << "\nItem 1: "; a.display();
    cout << "\nItem 2: "; b.display();
    cout << endl;
    if (a.compatible(b)) {
        InventoryItem c = a + b;
        cout << "\nItems are compatible. Combined item:\n";
        c.display();
        cout << endl;
    } else {
        cout << "\nIncompatible items: product ID and/or unit price do not match.\n"
             << "Items cannot be combined.\n";
    }
    return 0;
}