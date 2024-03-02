#include <iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class trade{
    public:
    int AGcoin, balanc
    int bitcoin;
    int deposit, withdraw;
    int total_equity = 100;
    int predict;
    int AGcoin_value;
    int bitcoin_value;
    int crypto_invest;
    int crypto_return;

    vector<pair<string, int >> transactions ;

    double Deposit(int money)
    {
        deposit += money;
        balance += money;
        transactions.push_back({ "Deposit:", money });
    }

    void Get_account_information()
    {
 
        cout << "Money Details:\n";
        cout << "Bank Balance:" << balance << endl;
        cout << "AG-coin:" << AGcoin << endl;
        cout << "Bitcoin:" << bitcoin << endl;
    }

    bool Withdraw(int money)
    {
        if (money > balance) {
            return false;
        }
        withdraw += money;
        balance -= money;
        transactions.push_back({ "Withdraw:", money });
        return true;
    }

    bool buy_crypto()
    {
        int option;
        cout << "Want to purchase AG-coin press 1 else "
                "for bitcoin press 2\n";
        cin >> option;
 
        // Checking equity
        if (total_equity != 0) {
            srand(time(NULL));
            int luck = rand();
 
            // Checking if random number is divisible by
            // 251 to check (random case for buying  crypto
            // used)
            if (luck % 251 == 0) {
                if (option == 1) {
                    AGcoin += 1;
                    balance -= AGcoin_value;
                    crypto_invest
                        += (AGcoin)*AGcoin_value;
                }
                else {
                    bitcoin += 1;
                    balance -= bitcoin_value;
                    crypto_invest += bitcoin_value;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
 
        return true;
    }

    bool sell_crypto()
    {
        int option;
        cout << "Want to sell AG-coin press 1 else for " "bitcoin press 2\n";
        cin >> option;
 
        if (option == 2) {
            if (bitcoin == 0)
                return false;
            crypto_return += bitcoin_value;
            balance += bitcoin_value;
            transactions.push_back(
                { "Bitcoin Sold:", bitcoin_value });
            bitcoin -= 1;
        }
        else {
            if (AGcoin == 0)
                return false;
            crypto_return += AGcoin_value;
            balance += AGcoin_value;
            transactions.push_back(
                { "AG-coin Sold:", AGcoin_value });
            AGcoin -= 1;
        }
 
        return true;
    }

    trade()
    {
        crypto_invest = 0;
        crypto_return = 0;
        total_equity = 100;
        balance = 50000;
        AGcoin = 5000;
        bitcoin = 5000;
        withdraw = 0;
        deposit = 0;
        AGcoin_value = 100;
        bitcoin_value = 500;
    }
};

int main()
{
    trade person;
    int amount, choice;
    do {
        cout << endl;
        cout << "1. If want to have your Account Info "<< endl;
        cout << "2. If want to Deposit your money "<< endl;
        cout << "3. If want to withdraw your money "<< endl;
        cout << "4. If want to know your Buy Crypto "<< endl;
        cout << "5. If want to know your Sell Crypto "<< endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        int ans;
 
        switch (choice) {
        case 1:
            person.Get_account_information();
            break;
 
        case 2:
            cout << "Enter amount to deposit : ";
            cin >> amount;
            ans = person.Deposit(amount);
            if (ans)
                cout << "Successfully deposited money"<< endl;
            else
                cout << "Failed\n";
 
            break;
 
        case 3:
            cout << "Enter amount to withdrawn : ";
            cin >> amount;
            person.Withdraw(amount);
 
            if (ans)
                cout << "Successfully withdrawn Amount"
                     << endl;
            else
                cout << "Not Enough Balance\n";
 
            break;
 
        case 4:
            ans = person.buy_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Better Luck next time\n";
            break;
 
        case 5:
            ans = person.sell_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Not Enough Cryptocoins\n";
            break;

        case 6:
        cout << "Exiting..." << endl;
                break;
 
        default:
            exit(0);
            break;
        }
     }while(choice != '6');
}
