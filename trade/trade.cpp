#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Include the <iomanip> header file for stream manipulations
#include <limits> 

using namespace std;

class TradingApp {
private:
    double balance;
    double profitLoss;
    double bitcoins;
    double dogecoins;
    double ripplecoin;
    double totalBitcoinsPurchased;
    double totalripplecoinsPurchased;
    double totalDogecoinsPurchased;
    double totalBitcoinsSold;
    double totalripplecoinsSold;
    double totalDogecoinsSold;
    double bitcoinprice;
    double dogecoinprice;
    double ripplecoinprice;

    vector<string> transactions;

public:
    TradingApp() : balance(0), profitLoss(0), bitcoins(0.0), dogecoins(0.0),ripplecoin(0.0),totalBitcoinsPurchased(0), totalDogecoinsPurchased(0),totalripplecoinsPurchased(0), totalBitcoinsSold(0), totalDogecoinsSold(0),totalripplecoinsSold(0)  {}

    void getAccountInfo() {
        cout << "Balance: " << balance << endl;
        cout << "Profit/Loss: " << profitLoss << endl;
        cout << "Bitcoins: " << bitcoins << endl;
        cout << "Dogecoins: " << dogecoins << endl;
        cout << "Ripplecoins: " << ripplecoin << endl;
    }

    // void depositMoney(double amount) {
    //     balance += amount;
    //     transactions.push_back("Deposit: $" + to_string(amount));
    //     cout << "....Money deposited successfully. Balance updated....\n";

    // }
    void depositMoney(double amount) {
    if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive value for deposit." << endl;
        return;
    }
    
    balance += amount;
    transactions.push_back("Deposit: $" + to_string(amount));
    cout << "....Money deposited successfully. Balance updated....\n";
}


    bool withdrawMoney(double amount) {
    if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive value." << endl;
        return false;
    }
    
    if (amount > balance) {
        cout << ".....Insufficient balance in your account....." << endl;
        return false;
    }
    
    balance -= amount;
    transactions.push_back("Withdraw: $" + to_string(amount));
    cout << "....Money withdrawn successfully. Balance updated....\n";
    return true;
}


    void buyShares(string type, double amount) {
    double bitcoinPrice = 50000.0;
    double dogecoinPrice = 30000.0;
    double ripplecoinPrice = 40000.0;

    if (type == "Bitcoin") {
        double bitcoinAmount = amount * bitcoinPrice;
        if (balance >= bitcoinAmount) { // Corrected balance check
            bitcoins += amount;
            totalBitcoinsPurchased += amount;
            balance -= bitcoinAmount;
            transactions.push_back("Bought " + to_string(amount) + " Bitcoin. New balance: $" + to_string(balance));
            cout << "Bought  " << amount << " share of Bitcoin at rate of $" <<bitcoinAmount<<" Bitcoinprice. New balance: $" << balance << "\n";
        } else {
            cout << "Insufficient funds to buy Bitcoin.\n";
        }
    } else if (type == "Dogecoin") {
        double dogecoinAmount = amount * dogecoinPrice;
        if (balance >= dogecoinAmount) { // Corrected balance check
            dogecoins += amount;
            totalDogecoinsPurchased += amount;
            balance -= dogecoinAmount;
            transactions.push_back("Bought " + to_string(amount) + " Dogecoin. New balance: $" + to_string(balance));
            cout << "Bought " << amount << " share of Dogecoin at rate of $"<<dogecoinAmount<<" Dogecoin. New balance: $" << balance << "\n";
        } else {
            cout << "Insufficient funds to buy Dogecoin.\n";
        }
    }else if (type == "Ripplecoin") {
        double ripplecoinAmount = amount * ripplecoinPrice;
        if (balance >= ripplecoinAmount) { // Corrected balance check
            dogecoins += amount;
            totalripplecoinsPurchased += amount;
            balance -= ripplecoinAmount;
            transactions.push_back("Bought " + to_string(amount) + " Ripplecoin. New balance: $" + to_string(balance));
            cout << "Bought " << amount << " share of Ripplecoin at rate of $"<<ripplecoinAmount<<" Ripplecoin. New balance: $" << balance << "\n";
        } else {
            cout << "Insufficient funds to buy Ripplecoin.\n";
        }
    } else {
        cout << "Invalid currency \n";
    }
}

    
    void sellShares(string type, double amount) {
        // Implementation for selling cryptocurrency
        if (type == "Bitcoin") {
            if (bitcoins >= amount) {
                bitcoins -= amount;
                balance += amount * 5000; // Assuming 1 Bitcoin = 5000
                transactions.push_back("Sold " + to_string(amount) + " Bitcoins");
                cout << ".....bitcoin sold successfully....." << endl;
            } else {
                cout << "Insufficient Bitcoins." << endl;
            }
        } else if (type == "Dogecoin") {
            if (dogecoins >= amount) {
                dogecoins -= amount;
                balance += amount * 0.2; // Assuming 1 Dogecoin = 0.2
                transactions.push_back("Sold " + to_string(amount) + " Dogecoins");
                cout << ".....Dogecoin sold successfully......" << endl;
            } else {
                cout << "Insufficient Dogecoins." << endl;
            }
        }
    }

// void buyShares(string type, double amount) {
//     double bitcoinPrice = 50000.0;
//     double dogecoinPrice = 30000.0;

//     double sharePrice = (type == "Bitcoin") ? bitcoinPrice : dogecoinPrice;
//     double shareAmount = (type == "Bitcoin") ? bitcoins : dogecoins;
    
//     double purchaseCost = amount * sharePrice;
    
//     if (balance >= purchaseCost) {
//         shareAmount += amount;
//         if (type == "Bitcoin") {
//             bitcoins = shareAmount;
//             totalBitcoinsPurchased += amount;
//         } else {
//             dogecoins = shareAmount;
//             totalDogecoinsPurchased += amount;
//         }
//         balance -= purchaseCost;
//         profitLoss -= purchaseCost; // Deduct purchase cost from profit/loss
//         transactions.push_back("Bought " + to_string(amount) + " " + type + ". New balance: $" + to_string(balance));
//         cout << "Bought " << amount << " share of " << type << " at rate of $" << purchaseCost << ". New balance: $" << balance << "\n";
//     } else {
//         cout << "Insufficient funds to buy " << type << ".\n";
//     }
// }

// void sellShares(string type, double amount) {
//     double sharePrice = (type == "Bitcoin") ? bitcoinprice : dogecoinprice;
//     double shareAmount = (type == "Bitcoin") ? bitcoins : dogecoins;
    
//     double sellAmount = amount * sharePrice;
    
//     if (shareAmount >= amount) {
//         shareAmount -= amount;
//         if (type == "Bitcoin") {
//             bitcoins = shareAmount;
//             totalBitcoinsSold += amount;
//         } else {
//             dogecoins = shareAmount;
//             totalDogecoinsSold += amount;
//         }
//         balance += sellAmount;
//         profitLoss += sellAmount; // Add sell amount to profit/loss
//         transactions.push_back("Sold " + to_string(amount) + " " + type + ". New balance: $" + to_string(balance));
//         cout << "Sold " << amount << " share of " << type << ". New balance: $" << balance << "\n";
//     } else {
//         cout << "Insufficient " << type << " shares.\n";
//     }
// }

    void checkTransactions() {
        // Implementation for checking transactions
         for (const auto& transaction : transactions) {
            cout << transaction << endl;
        }
    }

    
    void updatePrices() {
    // Here, you would implement the logic to fetch the latest prices for Bitcoin and Dogecoin
    // For example, you might fetch the prices from an API or read them from a file
    
    // Assign some dummy values for demonstration purposes
    bitcoinprice = 50000.0;
    dogecoinprice = 30000.0;
    ripplecoinprice = 40000.0;
}

void checkSharePrices() {
    // Update the prices before displaying them
    updatePrices();

    // Check if the prices have been updated successfully
    if (bitcoinprice <= 0 || dogecoinprice <= 0 || ripplecoinprice <=0) {
        cout << "Prices not available. Please update prices first." << endl;
        return;
    }

    // Display the current Bitcoin price
    cout << "Current Bitcoin price: $" << fixed << setprecision(2) << bitcoinprice << endl;

    // Display the current Dogecoin price
    cout << "Current Dogecoin price: $" << fixed << setprecision(2) << dogecoinprice << endl;
    cout << "Current Ripplecoin price: $" << fixed << setprecision(2) << ripplecoinprice << endl;
}

    void checkAccountBalance() {
        // Implementation for checking account balance
        cout << "Account balance: $" << balance << endl;
    }

    void getPurchaseSummary() {
        cout << "Total Bitcoins Share Purchased: $" << totalBitcoinsPurchased << endl;
        cout << "Total Dogecoins Share Purchased: $" << totalDogecoinsPurchased << endl;
        cout << "Total Ripplecoins Share Purchased: $" << totalripplecoinsPurchased << endl;
    }

    void getSaleSummary() {
        cout << "Total Bitcoins Sold: $" << totalBitcoinsSold << endl;
        cout << "Total Dogecoins Sold: $" << totalDogecoinsSold << endl;
        cout << "Total Ripplecoins Sold: $" << totalripplecoinsSold << endl;
    }
};

int main() {
    // Implementation for main function
     string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Simulate login check
    if (username == "user" && password == "pass") {
        cout << "\n-------Login successful.--------\n";
        TradingApp app;
        int choice;
        double amount;
        string cryptoType;

        while (true) {
            cout << "\n --------TRADING SOFTWARE---------\n";
            cout << "\nTrading Application Menu:\n";
            cout << "1. Get Account Info\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Buy Shares\n";
            cout << "5. Sell Shares\n";
            cout << "6. Check Transactions\n";
            cout << "7. Check Share Prices\n";
            cout << "8. Check Account Balance\n";
            cout << "9. total purchased\n";
            cout << "10. total sold\n";
            cout << "11. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    app.getAccountInfo();
                    break;
                case 2:
                    cout << "Enter amount to deposit: $";
                    cin >> amount;
                    app.depositMoney(amount);
                    
                    break;
                case 3:
                    cout << "Enter amount to withdraw: $ ";
                    cin >> amount;
                    app.withdrawMoney(amount);
                    break;
                 case 4:
                    cout << "Choose the type of cryptocurrency to buy:\n";
                    cout << "1. Bitcoin\n";
                    cout << "2. Dogecoin\n";
                    cout << "3. Ripplecoin\n";
                    cout << "Enter the option number: ";

                    if (!(cin >> choice)) {
                        cout << "Invalid input. Please enter a number.\n";
                        cin.clear(); // Clear the fail state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                        continue;
                    }

                    // Validate the option
                    if (choice < 1 || choice > 3) {
                        cout << "Invalid option. Please choose a valid option.\n";
                        break; // Break out of the switch case to return to the main menu
                    }

                    // Map the numeric option to cryptocurrency type
                    switch (choice) {
                        case 1:
                            cryptoType = "Bitcoin";
                            break;
                        case 2:
                            cryptoType = "Dogecoin";
                            break;
                        case 3:
                            cryptoType = "Ripplecoin";
                            break;
                    }

                    // Proceed with buying shares
                    cout << "Enter the amount to buy: $ ";
                    cin >> amount;
                    app.buyShares(cryptoType, amount);
                    break;
                case 5:
                    cout << "Enter type of cryptocurrency (Bitcoin/Dogecoin/Ripplecoin): ";
                    cin >> cryptoType;
                    cout << "Enter amount to sell: $ ";
                    cin >> amount;
                    app.sellShares(cryptoType, amount);
                    break;
                case 6:
                    app.checkTransactions();
                    break;
                case 7:
                    app.checkSharePrices();
                    break;
                case 8:
                    app.checkAccountBalance();
                    break;
                case 9:
                    app.getPurchaseSummary();
                    break;
                case 10:
                    app.getSaleSummary();
                    break;
                case 11:
                    cout << "Exiting the application.\n";
                    return 0;
                    default:
                    cout << "Invalid choice. Please try again.\n";
                    cin.clear(); // Clear the fail state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input

            }
        }
    } else {
        cout << "Login failed.\n";
    }

    return 0;
}
