#include <iostream>
using namespace std;
class Account;

class Manager{
public:
    void displayAccountDetails(Account & acc);
    void deposit(Account & acc, float amount);
    void withdraw(Account & acc, float amount);
};

class Account{
private:
    int accountNumber;
    float balance;
public:

    friend class Manager;
    friend void transferFunds(Account & from, Account & to, float amount);

    Account(int num, float bal){
        accountNumber = num;
        balance = bal;
    }
};

void Manager::displayAccountDetails(Account & acc){
    cout<<"Account Number: "<<acc.accountNumber<<endl;
    cout<<"Balance: "<<acc.balance<<endl;
}

void Manager::deposit(Account & acc, float amount){
    acc.balance += amount; 
    cout<<"Amount deposited successfully"<<endl;
}

void Manager::withdraw(Account & acc, float amount){
    if(amount> acc.balance){
        cout<<"Sorry the amount to be withdrawn is more than the balance avaliable."<<endl;
    }else{
        acc.balance -= amount;
        cout<<"Amount withdrawn successfully"<<endl;
    }
}

void transferFunds(Account & from, Account & to, float amount){
    if(amount> from.balance){
        cout<<"Sorry the amount to be withdrawn is more than the balance avaliable."<<endl;
    }else{
        from.balance -= amount;
        to.balance += amount;
    }
}

int main(){
    Account acc1(101, 500.0);
    Account acc2(102, 300.0);

    Manager manager;

    cout << "Initial Account Details:\n";
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    manager.deposit(acc1, 200);
    manager.withdraw(acc2, 100);
    transferFunds(acc1, acc2, 250);

    cout << "\nFinal Account Details:\n";
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    return 0;
}