#include <iostream>
#include <string>
using namespace std;

class WalletManager;

class DigitalWallet {
private:
    string userName, walletStatus;
    double walletBalance;

public:
    DigitalWallet(string name, double balance, string status = "Active")
        : userName(name), walletBalance(balance), walletStatus(status) {}

    friend class WalletManager;
};

class WalletManager {
public:
    // 1. Display wallet details
    void displayWalletDetails(const DigitalWallet& w) {
        cout << "\n--- Wallet Info ---\nUser: " << w.userName 
             << "\nBalance: $" << w.walletBalance 
             << "\nStatus: " << w.walletStatus << "\n-------------------\n";
    }

    // 2. Add money
    void addMoney(DigitalWallet& w, double amount) {
        if (w.walletStatus != "Active") cout << "Error: Wallet is " << w.walletStatus << ".\n";
        else if (amount > 0) cout << "Added $" << amount << ". Balance: $" << (w.walletBalance += amount) << endl;
    }

    // 3. Deduct money
    void deductMoney(DigitalWallet& w, double amount) {
        if (w.walletStatus != "Active") cout << "Error: Wallet is " << w.walletStatus << ".\n";
        else if (amount > w.walletBalance) cout << "Error: Insufficient balance ($" << w.walletBalance << ").\n";
        else if (amount > 0) cout << "Deducted $" << amount << ". Remaining: $" << (w.walletBalance -= amount) << endl;
    }

    // 4. Disable wallet
    void disableWallet(DigitalWallet& w) {
        w.walletStatus = "Disabled";
        cout << "Wallet disabled successfully.\n";
    }

    // 5. Display wallet status
    void displayWalletStatus(const DigitalWallet& w) {
        cout << "Current Status: " << w.walletStatus << endl;
    }
};

int main() {
    string name;
    double initialBalance, addAmt, deductAmt;

    // Get user input
    cout << "Enter User Name: ";
    getline(cin, name);
    cout << "Enter Initial Balance: $";
    cin >> initialBalance;

    DigitalWallet wallet(name, initialBalance);
    WalletManager wm;

    // 1. Display Details
    wm.displayWalletDetails(wallet);

    // 2. Add Money
    cout << "Enter amount to add: $";
    cin >> addAmt;
    wm.addMoney(wallet, addAmt);

    // 3. Deduct Money
    cout << "Enter amount to deduct: $";
    cin >> deductAmt;
    wm.deductMoney(wallet, deductAmt);

    // 4 & 5. Status & Disable
    wm.displayWalletStatus(wallet);
    wm.disableWallet(wallet);
    wm.displayWalletDetails(wallet);

    return 0;
}