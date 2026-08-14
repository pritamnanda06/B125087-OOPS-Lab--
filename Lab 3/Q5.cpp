#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string bookTitle;
    string author;
    double price;

public:
    void acceptDetails() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, bookTitle);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Price: ";
        cin >> price;
    }

    void displayDetails() const {
        cout << "\n--- Book Details ---" << endl;
        cout << "Book ID    : " << bookID << endl;
        cout << "Title      : " << bookTitle << endl;
        cout << "Author     : " << author << endl;
        cout << "Price      : $" << price << endl;
    }
};

int main() {
    Book *b = new Book;

    b->acceptDetails();
    b->displayDetails();

    delete b;
    return 0;
}