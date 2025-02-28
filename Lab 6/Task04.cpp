#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    void setAccountDetails(int accNum, float bal) {
        accountNumber = accNum;
        balance = bal;
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    void setSavingsDetails(int accNum, float bal, float rate) {
        setAccountDetails(accNum, bal);
        interestRate = rate;
    }

    void displayDetails()   {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    void setCheckingDetails(int accNum, float bal, float limit) {
        setAccountDetails(accNum, bal);
        overdraftLimit = limit;
    }

    void displayDetails()  {
        Account::displayDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings;
    CheckingAccount checking;

    int accNum;
    float balance, interestRate, overdraftLimit;

    cout << "Enter Savings Account Number: ";
    cin >> accNum;
    cout << "Enter Balance: ";
    cin >> balance;
    cout << "Enter Interest Rate: ";
    cin >> interestRate;
    savings.setSavingsDetails(accNum, balance, interestRate);

    cout << "\nEnter Checking Account Number: ";
    cin >> accNum;
    cout << "Enter Balance: ";
    cin >> balance;
    cout << "Enter Overdraft Limit: ";
    cin >> overdraftLimit;
    checking.setCheckingDetails(accNum, balance, overdraftLimit);

    cout << "\n--- Savings Account Details ---\n";
    savings.displayDetails();

    cout << "\n--- Checking Account Details ---\n";
    checking.displayDetails();

    return 0;
}
