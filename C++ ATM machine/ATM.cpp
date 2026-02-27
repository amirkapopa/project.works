//U2510164 AMIR PULATOV



#include "ATM.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

/* ===== STATIC DEFINITIONS ===== */
int Account::accountCount = 0;
int Balance::balanceObjects = 0;
int ATM::atmCount = 0;

/* ================= ACCOUNT ================= */
Account::Account(int card, string name, int pin) {
    if (card <= 0)
        throw invalid_argument("Invalid card number");
    if (pin < 1000 || pin > 9999)
        throw invalid_argument("PIN must be 4 digits");

    bankCard = card;
    accountName = name;
    pinNumber = pin;
    accountCount++;
}

void Account::display() const {
    cout << "Account Details:\n";
    cout << "Card Number: " << bankCard << endl;
    cout << "Name: " << accountName << endl;
    cout << "PIN: " << pinNumber << endl;
}

int Account::getAccountCount() {
    return accountCount;
}

/* ================= BALANCE ================= */
Balance::Balance(double initialBalance) {
    if (initialBalance < 0)
        balance = 0;
    else
        balance = initialBalance;

    balanceObjects++;
}

void Balance::deposit(double amount) {
    if (amount > 0)
        balance += amount;
    else
        cout << "Invalid deposit amount. Must be > 0.\n";
}

bool Balance::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void Balance::showBalance() const {
    cout << fixed << setprecision(2);
    cout << "Balance: Current Balance: " << balance << endl;
}

int Balance::getBalanceObjects() {
    return balanceObjects;
}

/* ================= ATM ================= */
ATM::ATM(int card, string name, int pin, double initialBalance)
    : account(card, name, pin), balance(initialBalance)
{
    atmCount++;
}

void ATM::deposit(double amount) {
    balance.deposit(amount);
}

bool ATM::withdraw(double amount) {
    return balance.withdraw(amount);
}

void ATM::print() const {
    account.display();
    balance.showBalance();
}

int ATM::getAtmCount() {
    return atmCount;
}

/* ================= MAIN ================= */
int main() {
    int n;
    cout << "Enter number of ATM users: ";
    cin >> n;

    // Dynamic array of pointers to ATM
    ATM** users = new ATM*[n];

    for (int i = 0; i < n; i++) {
        int card, pin;
        string name;
        double bal;

        cout << "\nEnter info for user " << i + 1 << endl;
        cout << "Card number: ";
        cin >> card;
        cout << "Account name: ";
        cin >> name;
        cout << "PIN (4 digits): ";
        cin >> pin;
        cout << "Initial balance: ";
        cin >> bal;

        users[i] = new ATM(card, name, pin, bal);
    }

    cout << "\nBEFORE TRANSACTIONS\n";
    for (int i = 0; i < n; i++) {
        cout << "User " << i + 1 << ":\n";
        users[i]->print();
        cout << endl;
    }

    // ===== DEPOSIT =====
    int index;
    double amount;

    cout << "Enter user index for deposit (1.." << n << "): ";
    cin >> index;

    if (index >= 1 && index <= n) {
        cout << "Enter deposit amount: ";
        cin >> amount;

        users[index - 1]->deposit(amount);
    } else {
        cout << "Invalid user index.\n";
    }

    // ===== WITHDRAW =====
    cout << "Enter user index for withdrawal (1.." << n << "): ";
    cin >> index;

    if (index >= 1 && index <= n) {
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        if (!users[index - 1]->withdraw(amount))
            cout << "Withdrawal failed.\n";
    } else {
        cout << "Invalid user index.\n";
    }

    cout << "\nAFTER TRANSACTIONS\n";
    for (int i = 0; i < n; i++) {
        cout << "User " << i + 1 << ":\n";
        users[i]->print();
        cout << endl;
    }

    cout << "STATIC COUNTERS\n";
    cout << "Total Account objects: " << Account::getAccountCount() << endl;
    cout << "Total Balance objects: " << Balance::getBalanceObjects() << endl;
    cout << "Total ATM objects: " << ATM::getAtmCount() << endl;

    // Free memory
    for (int i = 0; i < n; i++)
        delete users[i];
    delete[] users;

    return 0;
}