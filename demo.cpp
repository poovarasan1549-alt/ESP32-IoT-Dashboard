#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Transaction {
    string desc;
    double amount;
};

int main() {
    vector<Transaction> transactions;
    double income = 0, expense = 0;
    cout << "==== Poovarasan Expense Tracker (C++ Console Demo) ====\n";

    while (true) {
        cout << "\n1. Add Income\n2. Add Expense\n3. Show Summary\n4. Exit\nChoose: ";
        int choice;
        cin >> choice;

        if (choice == 4) break;

        Transaction t;
        cout << "Enter description: ";
        cin.ignore();
        getline(cin, t.desc);
        cout << "Enter amount: ";
        cin >> t.amount;

        if (choice == 1) {
            income += t.amount;
            t.amount = t.amount;
        } else if (choice == 2) {
            expense += t.amount;
            t.amount = -t.amount;
        }
        transactions.push_back(t);

        if (choice == 3) {
            cout << "\n--- Summary ---\n";
            cout << "Total Income: ₹" << income << "\n";
            cout << "Total Expense: ₹" << expense << "\n";
            cout << "Balance: ₹" << (income - expense) << "\n";
        }
    }

    cout << "\nThank you for using Poovarasan Expense Tracker!\n";
    return 0;
}
