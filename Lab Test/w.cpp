#include <iostream>
using namespace std;

class Wallet {
private:
    int walletID;
    double balance;
    double* transactions;   
    int capacity;
    int count;

public:
    Wallet() : walletID(0), balance(0), transactions(nullptr), capacity(0), count(0) {} 

    void initWallet(int id, double initialBalance, int maxTransactions) {
        walletID = id;
        balance = initialBalance;
        capacity = maxTransactions;
        count = 0;
        transactions = new double[capacity];
    }

int main(){

    return 0;
}