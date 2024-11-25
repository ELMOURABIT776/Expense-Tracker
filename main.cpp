#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Expense {
    string category;
    double amount;
};

class ExpenseTracker {

    vector<Expense> expenses;

public:
    void addExpense(string category, double amount) {
        Expense newExpense = {category, amount};
        expenses.push_back(newExpense);
    }

    double getTotalExpenditure() {
        double total = 0;
        for (auto &expense : expenses) {
            total += expense.amount;
        }
        return total;
    }

    void displayExpenses() {
        for (auto &expense : expenses) {
            cout << "Category: " << expense.category << ", Amount: " << expense.amount << endl;
        }
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;
    do {
        cout << "1. Add Expense\n2. View Total Expenditure\n3. View All Expenses\n4. Exit\n";
        cin >> choice;
        if (choice == 1) {
            string category;
            double amount;
            cout << "Enter expense category: ";
            cin >> category;
            cout << "Enter amount: ";
            cin >> amount;
            tracker.addExpense(category, amount);
        } else if (choice == 2) {
            cout << "Total Expenditure: " << tracker.getTotalExpenditure() << endl;
        } else if (choice == 3) {
            tracker.displayExpenses();
        }
    } while (choice != 4);

    return 0;
}
