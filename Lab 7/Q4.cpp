// Q4: University Resource Access - Multiple Inheritance
#include <iostream>
using namespace std;

class LibraryAccess {
protected:
    int books;
public:
    LibraryAccess(int b) : books(b) {}
};

class LaboratoryAccess {
protected:
    int pending;
public:
    LaboratoryAccess(int p) : pending(p) {}
};

class StudentAccess : public LibraryAccess, public LaboratoryAccess {
public:
    StudentAccess(int b, int p) : LibraryAccess(b), LaboratoryAccess(p) {}
    void display() {
        cout << "\nBooks borrowed: " << books << "\nPending submissions: " << pending
             << "\nAccess: " << (books <= 5 && pending == 0 ? "FULL" : "RESTRICTED") << endl;
    }   
};

int main() {
    int b, p;
    cout << "Enter books borrowed and pending lab submissions: ";
    cin >> b >> p;
    StudentAccess s(b, p);
    s.display();
}