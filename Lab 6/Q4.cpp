#include <iostream>
using namespace std;

class AccountBalance {
public:
    double balance;
    AccountBalance(double b = 0) { balance = b; }
    AccountBalance operator-() { return AccountBalance(-balance); }
};

int main() {
    double b;
    cout << "Enter balance: ";
    cin >> b;

    AccountBalance a(b), n = -a;
    cout << "Original balance: " << a.balance << endl;
    cout << "Negated balance : " << n.balance << endl;
    cout << (a.balance == b ? "Verified: original balance is unchanged.\n"
                            : "Original balance was modified!\n");
}