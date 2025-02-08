#include <iostream>
#include <string>
using namespace std;

class Wallet
{
private:
    string ownerName;
    float totalBalance;
    string transactionHistory[100][2];
    int pointer;

public:
    Wallet(string ownerName)
    {
        this->ownerName = ownerName;
        totalBalance = 0;
        pointer = 0;
    }

    void addMoney(float money)
    {
        totalBalance += money;
        transactionHistory[pointer][0] = "added";
        transactionHistory[pointer][1] = std::to_string(money);
        pointer++;
    }

    void spendMoney(float money)
    {
        if (totalBalance >= money)
        {
            totalBalance -= money;
            transactionHistory[pointer][0] = "subtracted";
            transactionHistory[pointer][1] = std::to_string(money);
            pointer++;
        }
        else
        {
            cout << "you dont have enough money" << endl;
        }
    }

    void displayTransactionHistory()
    {
        for (int i = 0; i < pointer; i++)
        {
            cout << transactionHistory[i][0] << ": " << transactionHistory[i][1] << endl;
        }
    }
};

int main()
{
    Wallet saad("saad merchant");
    saad.addMoney(100);
    saad.spendMoney(50);
    saad.spendMoney(300);
    saad.displayTransactionHistory();

    return 0;
}