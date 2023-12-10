//
// Created by Tadiwanashe Dzvoti on 19/11/2023.
//

#include <iostream>
#include <vector>
#include <unordered_map>

// Base class for Account
class Account{
private:
    std::string accountHolderName;
    int accountNumber;
    int balance;
    int pin;

public:
    // Constructor to create bank account
    Account(){
        std::cout <<"Enter your name: ";
        std::cin>> accountHolderName;

        accountNumber = rand() % 100000;
        std::cout << "Your account number is " << accountNumber << std::endl;

        pin = rand() % 1000;
        std::cout << "Your pin number is " << pin << std::endl;

        balance = 0;
        std::cout << "Your opening balance is £" << balance << std::endl;

        std::cout <<" "<<std::endl;

    }

    bool verifyPin(){
        int pinAttempt;
        std::cout <<"Enter pin: ";
        std::cin >> pinAttempt;
        std::cout <<" "<<std::endl;

        if(pinAttempt == pin){
            return true;
        }
        else{
            std::cout <<"Incorrect Pin" << std::endl;
            std::cout <<" "<<std::endl;
            return false;
        }
    }

    // Deposits money into the bank account
    void deposit(){
        bool flag = verifyPin();

        if(flag){
            int deposit;
            std::cout << "Enter deposit amount: ";
            std::cin >> deposit;
            balance += deposit;
            std::cout << "Your new balance is: £" << balance << std::endl;
            std::cout <<" "<<std::endl;
        }
        else{
            std::cout << "Incorrect pin" << std::endl;
            std::cout <<" "<<std::endl;
        }
    }

    void withdraw(){
        bool flag = verifyPin();

        if(flag){
            int withdraw; // withdrawal amount
            std::cout << "Enter withdraw amount: ";
            std::cin >> withdraw;
            std::cout <<" "<<std::endl;
            if(withdraw > balance){
                std::cout << "Insufficient Funds" << std::endl;
                std::cout <<" "<<std::endl;
            }
            else {
                balance -= withdraw;
                std::cout << "Your new balance is: £" << balance << std::endl;
                std::cout <<" "<<std::endl;
            }
        }
        else{
            std::cout << "Incorrect pin" << std::endl;
            std::cout <<" "<<std::endl;
        }
    }

    void printAccountInformation(Account account){
        std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
        std::cout << "Account Holder Name: " << account.getAccountHolderName() << std::endl;
        std::cout << "Account Balance: £" << account.getBalance() << std::endl;
        std::cout <<" "<<std::endl;
    }

    void closeAccount(){

    }

    int getAccountNumber() const{
        return accountNumber;
    }

    std::string getAccountHolderName(){
        return accountHolderName;
    }

    int getBalance() const{
        return balance;
    }

};

// Base class for bank
class Bank{
private:
    std::string BankName;
    std::unordered_map<int,Account> accounts;
public:
    explicit Bank(std::string bankname){
        BankName = std::move(bankname);
    }

    // Add account to account vector and return the index as the id.
    void addAccount(const Account& account){
        int id = account.getAccountNumber();
        accounts.insert({id, account});
    }

    void deleteAccount(int id){
        bool flag = doesAccountExist(id);
        if(flag) {
            accounts.erase(id);
            std::cout <<"Account " << id <<" successfully deleted." << std::endl;
            std::cout <<" "<<std::endl;
        }
    }

    bool doesAccountExist(int id){
        if(accounts.find(id) != accounts.end()){
            return true;
        }
        else{
            std::cout <<"Account not found!" << std::endl;
            std::cout <<" "<<std::endl;
            return false;
        }
    }

    void displayAccountInformation(int id){
        bool acc_flag = doesAccountExist(id);
        if(acc_flag){
            Account account = getAccount(id);
            bool pin_flag = account.verifyPin();
            if(pin_flag){
                account.printAccountInformation(account);
            }
        }
    }

    std::string getName(){
        return BankName;
    }

    Account getAccount(int id){
        return accounts[id];
    }


};


int main(){
    Bank bank = Bank("Bank of Tadiwa");
    int entry;

    do {
        std::cout << "Welcome to the " << bank.getName() << std::endl;
        std::cout << "1. Create a New Account" << std::endl;
        std::cout << "2. Display Account Info" << std::endl;
        std::cout << "3. Deposit Funds" << std::endl;
        std::cout << "4. Withdraw Funds" << std::endl;
        std::cout << "5. Delete Account" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout <<" "<<std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> entry;
        std::cout <<" "<<std::endl;

        switch (entry) {
            case 1: {
                Account acc = Account();
                bank.addAccount(acc);
                std::cout << "Account has been successfully created!" << std::endl;
                std::cout <<" "<<std::endl;
                break;
            }
            case 2: {
                int accountNumber;
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout <<" "<<std::endl;
                bank.displayAccountInformation(accountNumber);
                break;
            }
            default:{
                std::cout <<"Invalid choice, try again!" << std::endl;
                std::cout <<" "<<std::endl;
            }
        }

    }
    while(entry != 6);

    return 0;
}