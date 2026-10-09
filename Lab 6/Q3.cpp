#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    double price;
public:
    void input(const char* name) {
        cout << "Enter title of " << name << ": ";
        getline(cin >> ws, title);
        cout << "Enter price of " << name << ": ";
        cin >> price;
    }
    bool operator<(const Book& o) const {
        if (price != o.price) return price < o.price;
        return title < o.title;   // tie-break: lexicographic title
    }
    void display() const {
        cout << "\"" << title << "\" - Rs. " << price;
    }
};

int main() {
    Book b1, b2;
    b1.input("Book 1");
    b2.input("Book 2");
    cout << "\nBook 1: "; b1.display();
    cout << "\nBook 2: "; b2.display();
    cout << "\n\nBook 1 < Book 2 : " << (b1 < b2 ? "true" : "false") << endl;
    cout << "Book 2 < Book 1 : " << (b2 < b1 ? "true" : "false") << endl;
    if (b1 < b2) cout << "Book 1 is ranked lower (smaller).\n";
    else if (b2 < b1) cout << "Book 2 is ranked lower (smaller).\n";
    else cout << "Both books are identical in ranking.\n";
    return 0;
}