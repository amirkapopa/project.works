#ifndef UNTITLED_ATM_H
#define UNTITLED_ATM_H

#include <string>
using namespace std;

/* ================= ACCOUNT ================= */
class Account {
private:
    int bankCard;
    string accountName;
    int pinNumber;
    static int accountCount;

public:
    Account(int card, string name, int pin);
    void display() const;
    static int getAccountCount();
};

/* ================= BALANCE ================= */
class Balance {
private:
    double balance;
    static int balanceObjects;

public:
    Balance(double initialBalance);
    void deposit(double amount);
    bool withdraw(double amount);
    void showBalance() const;
    static int getBalanceObjects();
};

/* ================= ATM (COMPOSITION) ================= */
class ATM {
private:
    Account account;   // composition
    Balance balance;   // composition
    static int atmCount;

public:
    ATM(int card, string name, int pin, double initialBalance);

    void deposit(double amount);
    bool withdraw(double amount);

    void print() const;
    static int getAtmCount();
};

#endif