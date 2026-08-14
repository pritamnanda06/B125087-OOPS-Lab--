#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productID;
    string productName;
    double price;
    int quantity;

public:
    void accept() {
        cout << "Enter Product ID: ";
        cin >> productID;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, productName);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    double calculateCost() const {
        return price * quantity;
    }

    void display() const {
        cout << "ID: " << productID << " | Name: " << productName 
             << " | Price: $" << price << " | Qty: " << quantity 
             << " | Total Cost: $" << calculateCost() << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    Product *products = new Product[n];

    cout << "\nEnter details for " << n << " products:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        products[i].accept();
    }

    cout << "\n--- Product Inventory Report ---\n";
    double overallInventoryValue = 0.0;
    for (int i = 0; i < n; i++) {
        cout << "Product " << i + 1 << ": ";
        products[i].display();
        overallInventoryValue += products[i].calculateCost();
    }

    cout << "\nOverall Inventory Value: $" << overallInventoryValue << endl;

    delete[] products;
    return 0;
}