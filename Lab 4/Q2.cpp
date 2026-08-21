#include <iostream>
#include <string>
using namespace std;

class UserAccount {
private:
    string username;
    int loginAttempts;
    string accountStatus;

public:
    void acceptData() {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Unsuccessful Login Attempts: ";
        cin >> loginAttempts;
        cout << "Enter Account Status: ";
        cin >> accountStatus;
    }

    // Friend function declaration
    friend void checkAccount(const UserAccount& u);
};

// Friend function definition
void checkAccount(const UserAccount& u) {
    cout << "\n--- Two-Factor Login Check ---" << endl;
    cout << "Username: " << u.username << endl;
    cout << "Login Attempts: " << u.loginAttempts << endl;
    cout << "Account Status: ";
    if (u.loginAttempts >= 3) {
        cout << "Account Locked" << endl;
    } else {
        cout << "Account Active" << endl;
    }
}

int main() {
    UserAccount acc;
    acc.acceptData();
    checkAccount(acc);
    return 0;
}