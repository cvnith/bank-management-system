#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct BankAccount {
    string accountNumber;
    string accountHolderName;
    double balance;
};

unordered_map<string, BankAccount> accounts;

void createAccount(const string& accNumber, const string& accHolderName, double initialBalance) {
    accounts.emplace(accNumber, BankAccount{accNumber, accHolderName, initialBalance});
    cout << "Account created successfully." << endl;
}

void deposit(const string& accNumber, double amount) {
    auto it = accounts.find(accNumber);
    if (it != accounts.end()) {
        it->second.balance += amount;
        cout << "Deposit successful. Current balance: " << it->second.balance << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

void withdraw(const string& accNumber, double amount) {
    auto it = accounts.find(accNumber);
    if (it != accounts.end()) {
        if (it->second.balance >= amount) {
            it->second.balance -= amount;
            cout << "Withdrawal successful. Current balance: " << it->second.balance << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
}

void checkBalance(const string& accNumber) {
    auto it = accounts.find(accNumber);
    if (it != accounts.end()) {
        cout << "Account balance: " << it->second.balance << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

int main() {
    while (true) {
        cout << "\nBank Management System\n";
        cout << "1. Create a new account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check balance\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string accNumber, accHolderName;
                double initialBalance;
                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, accHolderName);
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                createAccount(accNumber, accHolderName, initialBalance);
                break;
            }
            case 2: {
                string accNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                deposit(accNumber, amount);
                break;
            }
            case 3: {
                string accNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                withdraw(accNumber, amount);
                break;
            }
            case 4: {
                string accNumber;
                cout << "Enter account number: ";
                cin >> accNumber;
                checkBalance(accNumber);
                break;
            }
            case 5:
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;  // Added break statement to exit the switch
        }
    }

    return 0;
}
