//
// Created by Tadiwanashe Dzvoti on 19/11/2023.
//

#include <iostream>
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

    void deleteAccount(int id){
        account.erase(account.begin() + id);
    }

    std::string getName(){
        return BankName;
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

    bool verifyPin(){
        int pinAttempt;
        std::cout <<"Enter pin: ";
        std::cin >> pinAttempt;

        if(pinAttempt == pin){
            return true;
        }
        else{
            std::cout <<"Incorrect Pin" << std::endl;
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
        }
        else{
            std::cout << "Incorrect pin" << std::endl;
        }
    }

    void withdraw(){
        bool flag = verifyPin();

        if(flag){
            int withdraw; // withdrawal amount
            std::cout << "Enter withdraw amount: ";
            std::cin >> withdraw;
            if(withdraw > balance){
                std::cout << "Insufficient Funds" << std::endl;
            }
            else {
                balance -= withdraw;
                std::cout << "Your new balance is: £" << balance << std::endl;
            }
        }
        else{
            std::cout << "Incorrect pin" << std::endl;
        }
    }

    void closeAccount(){

    }

};

int main(){
    Bank bank("Bank of Tadiwa");
    int choice;

    do {
        std::cout << "Welcome to the " << bank.getName() << std::endl;
        std::cout << "1. Create a New Account" << std::endl;
        std::cout << "2. Display Account Info" << std::endl;
        std::cout << "3. Deposit Funds" << std::endl;
        std::cout << "4. Withdraw Funds" << std::endl;
        std::cout << "5. Delete Account" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:

        }
    }
    while(true);

    return 0;
}