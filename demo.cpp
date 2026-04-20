// file: expense_tracker.cpp
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Transaction {
    string desc;
    double amount;
};

void clearBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Transaction> transactions;
    double income = 0.0, expense = 0.0;

    while (true) {
        cout << "\n1. Add Income\n2. Add Expense\n3. Show Summary\n4. Exit\nChoose: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            clearBuffer();
            cout << "Invalid input\n";
            continue;
        }

        if (choice == 4) break;

        if (choice == 1 || choice == 2) {
            Transaction t;

            clearBuffer(); // FIX: clean buffer before getline
            cout << "Enter description: ";
            getline(cin, t.desc);

            cout << "Enter amount: ";
            cin >> t.amount;

            if (cin.fail() || t.amount < 0) {
                cin.clear();
                clearBuffer();
                cout << "Invalid amount\n";
                continue;
            }

            if (choice == 1) {
                income += t.amount;        // ADD income
            } else {
                expense += t.amount;       // TRACK expense
                t.amount = -t.amount;      // STORE negative
            }

            transactions.push_back(t);
        }
        else if (choice == 3) {
            cout << "\n--- Summary ---\n";
            cout << "Income: ₹" << income << endl;
            cout << "Expense: ₹" << expense << endl;
            cout << "Balance: ₹" << (income - expense) << endl;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
