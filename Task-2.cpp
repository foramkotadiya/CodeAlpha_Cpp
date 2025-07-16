// TASK-2 -- Banking System

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
    public: 
       string type;
       double amount;
       Transaction(string t, double a): type(t), amount(a) {}
};

class Amount {
    public:
       int accNo;
       double balance;
       vector<Transaction> history;

       Account(int no): accNo(no), balance(0) {}

       void deposit(double amt) {
          balance += amt;
          history.push_back(Transaction("Deposit", amt));
       }

       bool withdraw(double amt) {
        if (amt > balance) return false;
        balance -= amt;
        history.push_back(Transaction("Withdraw", amt));
        return true;
       }

       void transfer(Account &to, double amt) {
        if (withdraw(amt)) {
            to.deposit(amt);
            history.push_back(Transaction("Transfer to " + to.to_string(), amt));
        }
       }

       void showTransctions() {
         for (auto t : history)
           cout << t.type <<": " << t.amount << endl;
       }

       string to_string() {
        return "Acc#" + std::to_string(accNo);
       }
};

class Customer {
    public:
    string name;
    Account acc;

    Customer(string n, int accNo): name(n), acc(accNo) {}

    void showDetails() {
        cout << "Name: " << name << ", Balance:" << acc.balance << endl;
        acc.showTransctions();
    }
};

int main() {
    Customer c1("Alice", 1001), c2("Bob", 1002);

    c1.acc.deposit(5000);
    c1.acc.withdraw(1000);
    c1.acc.transfer(c2.acc, 2000);

    cout << "\n---Alice Account ---\n";
    c1.showDetails();

    cout << "\n---Bob Account ---\n";
    c2.showDetails();

    return 0;
}


