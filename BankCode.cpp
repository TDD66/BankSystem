//
// Created by Tadiwanashe Dzvoti on 19/11/2023.
//

#include <iostream>
#include <utility>
#include <vector>

class Bank{
protected:
    std::string BankName;
    std::vector<int> account; // variable will hold account numbers and use them as identifiers.
public:
    explicit Bank(std::string bankname){
        BankName = std::move(bankname);
    }

    // Add account to account vector and return the index as the id.
    int addAccount(int account_number){
        account.push_back(account_number);
        return account.size() - 1;
    }


};

class Account:Bank{
private:
    std::string accountHolderName;
    int accountNumber;
    int balance;
    int pin;
    int id;

public:
    // Constructor to create bank account
    Account(): Bank(BankName){
        std::cout <<"Enter your name: ";
        std::cin>> accountHolderName;

        accountNumber = rand() % 100000;
        std::cout << "Your account number is " << accountNumber << std::endl;

        pin = rand() % 1000;
        std::cout << "Your pin number is " << pin << std::endl;

        balance = 0;
        std::cout << "Your opening balance is £" << balance << std::endl;

        // id will be used to find the bank account in the bank's storage.
        id = addAccount(accountNumber);
    }

    // Deposits money into the bank account
    void deposit(){
        int pinAttempt;
        int deposit;
        std::cout <<"Enter pin: ";
        std::cin >> pinAttempt;

        if(pinAttempt == pin){
            std::cout << "Enter deposit amount: ";
            std::cin >> deposit;
            balance += deposit;
            std::cout << "Your new balance is: £" << balance << std::endl;
        }
        else{
            std::cout << "Incorrect pin" << std::endl;
        }
    }

    void withdraw(){

    }

};

int main(){
    Bank bank("Bank");

    do {
        Account account1;
        account1.deposit();
    }
    while(true);

    return 0;
}