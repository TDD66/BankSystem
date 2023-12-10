//
// Created by Tadiwanashe Dzvoti on 19/11/2023.
//

#include <iostream>

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
    }

};

int main(){

    Account account1;
    account1.deposit();

    return 0;
}