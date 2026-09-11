#include <iostream>
using namespace std;

class Wallet {
private:
    int walletID;
    double balance;
    double* transactions;
    int capacity, count;

public:
    Wallet() : walletID(0), balance(0), transactions(nullptr), capacity(0), count(0) {}

    void init(int id, double bal, int max) {
        walletID = id;
        balance = bal;
        capacity = max;
        count = 0;
        transactions = new double[capacity];
    }

    // Overload 1: signed amount
    void add(double amount) {
        if (count >= capacity || (amount < 0 && -amount > balance)) return;
        balance += amount;
        transactions[count++] = amount;
    }

    // Overload 2: amount + type
    void add(double amount, char type) {
        if (count >= capacity) return;
        double val = (type == 'W' || type == 'w') ? -amount : amount;
        if (val < 0 && -val > balance) return;
        balance += val;
        transactions[count++] = val;
    }

    void display() const {
        cout << "ID: " << walletID << " | Balance: " << balance << " | Txns: ";
        for (int i = 0; i < count; i++) cout << transactions[i] << " ";
        cout << endl;
    }

    friend void compare(const Wallet& w1, const Wallet& w2);

    ~Wallet() { delete[] transactions; }
};

void compare(const Wallet& w1, const Wallet& w2) {
    cout << "Wallet " << w1.walletID << " (" << w1.balance << ") vs "
         << w2.walletID << " (" << w2.balance << "): ";
    if (w1.balance > w2.balance) cout << w1.walletID << " larger\n";
    else if (w2.balance > w1.balance) cout << w2.walletID << " larger\n";
    else cout << "Equal\n";
}

int main() {
    int n;
    cout << "Wallets: ";
    cin >> n;

    Wallet* wallets = new Wallet[n];

    for (int i = 0; i < n; i++) {
        int id, maxTx;
        double bal;
        cout << "\nWallet " << (i + 1) << " - ID: ";
        cin >> id;
        cout << "Balance: ";
        cin >> bal;
        cout << "Max txns: ";
        cin >> maxTx;
        wallets[i].init(id, bal, maxTx);

        int numTx;
        cout << "Transactions: ";
        cin >> numTx;
        for (int j = 0; j < numTx; j++) {
            cout << "Txn " << (j + 1) << " (1=signed, 2=type): ";
            int mode;
            cin >> mode;
            if (mode == 1) {
                double amt;
                cout << "Amount: ";
                cin >> amt;
                wallets[i].add(amt);
            } else {
                double amt;
                char type;
                cout << "Amount: ";
                cin >> amt;
                cout << "Type (D/W): ";
                cin >> type;
                wallets[i].add(amt, type);
            }
        }
    }

    cout << "\n--- Status ---\n";
    for (int i = 0; i < n; i++)
        wallets[i].display();

    if (n >= 2) {
        int a, b;
        cout << "Compare indices (1-" << n << "): ";
        cin >> a >> b;
        if (a >= 1 && a <= n && b >= 1 && b <= n)
            compare(wallets[a - 1], wallets[b - 1]);
    }

    delete[] wallets;
    return 0;
}
