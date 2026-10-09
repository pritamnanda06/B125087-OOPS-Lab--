#include <iostream>
using namespace std;

class AccountBalance {
    double balance;
public:
    AccountBalance(double b = 0) : balance(b) {}
    void input() {
        cout << "Enter account balance: ";
        cin >> balance;
    }
    AccountBalance operator-() const {      // unary minus
        return AccountBalance(-balance);
    }
    void display(const char* label) const {
        cout << label << balance << endl;
    }
};  

int main() {
    AccountBalance original;
    original.input();
    AccountBalance negated = -original;
    cout << endl;
    original.display("Original balance : ");
    negated.display ("Negated balance  : ");
    cout << "\nOriginal object unchanged after negation:\n";
    original.display("Original balance : ");
    return 0;
}