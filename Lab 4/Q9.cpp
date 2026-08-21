#include <iostream>
#include <string>
using namespace std;

class DigitalWallet {
private:
    string userName;
    double walletBalance;
    string walletStatus; // e.g., "Active", "Disabled"

public:
    void acceptData() {
        cout << "Enter User Name: ";
        cin.ignore();
        getline(cin, userName);
        cout << "Enter Wallet Balance: ";
        cin >> walletBalance;
        cout << "Enter Wallet Status (Active/Disabled): ";
        cin >> walletStatus;
    }

    // Declare WalletManager as a friend class
    friend class WalletManager;
};

class WalletManager {
public:
    void displayWalletDetails(const DigitalWallet& w) {
        cout << "\n--- Digital Wallet Details ---" << endl;
        cout << "User Name: " << w.userName << endl;
        cout << "Wallet Balance: $" << w.walletBalance << endl;
        cout << "Wallet Status: " << w.walletStatus << endl;
    }

    void addMoney(DigitalWallet& w, double amount) {
        if (amount > 0 && w.walletStatus == "Active") {
            w.walletBalance += amount;
            cout << "Successfully added $" << amount << " to " << w.userName << "'s wallet." << endl;
        } else {
            cout << "Failed to add money. Check wallet status or amount." << endl;
        }
    }

    void deductMoney(DigitalWallet& w, double amount) {
        if (w.walletStatus != "Active") {
            cout << "Wallet is disabled. Transaction failed." << endl;
            return;
        }
        if (w.walletBalance >= amount) {
            w.walletBalance -= amount;
            cout << "Successfully deducted $" << amount << " from " << w.userName << "'s wallet." << endl;
        } else {
            cout << "Insufficient balance! Transaction failed." << endl;
        }
    }

    void disableWallet(DigitalWallet& w) {
        w.walletStatus = "Disabled";
        cout << w.userName << "'s wallet has been disabled." << endl;
    }

    void displayWalletStatus(const DigitalWallet& w) {
        cout << "Current Wallet Status for " << w.userName << ": " << w.walletStatus << endl;
    }
};

int main() {
    DigitalWallet wallet;
    wallet.acceptData();
    WalletManager wm;

    wm.displayWalletDetails(wallet);
    double addAmt, deductAmt;
    cout << "Enter amount to add: ";
    cin >> addAmt;
    wm.addMoney(wallet, addAmt);

    cout << "Enter amount to deduct: ";
    cin >> deductAmt;
    wm.deductMoney(wallet, deductAmt);

    wm.displayWalletDetails(wallet);
    return 0;
}