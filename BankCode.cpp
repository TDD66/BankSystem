//
// Created by Tadiwanashe Dzvoti on 19/11/2023.
//

#include <iostream>
#include <utility>
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

    bool verifyPin() const{
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

        if (flag) {
            int deposit;
            std::cout << "Enter deposit amount: ";
            std::cin >> deposit;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout <<"Invalid input, please use a number." << std::endl;
                return;
            }
            balance += deposit;
            std::cout << "Your new balance is: £" << balance << std::endl;
            std::cout << " " << std::endl;
        } else {
            std::cout << "Incorrect pin" << std::endl;
            std::cout << " " << std::endl;
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



    static void printAccountInformation(Account account){
        std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
        std::cout << "Account Holder Name: " << account.getAccountHolderName() << std::endl;
        std::cout << "Account Balance: £" << account.getBalance() << std::endl;
        std::cout <<" "<<std::endl;
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
        bool acc_flag = doesAccountExist(id);
        if(acc_flag) {
            Account account = getAccount(id);
            bool pin_flag =  account.verifyPin();
            if(pin_flag) {
                accounts.erase(id);
                std::cout << "Account " << id << " successfully deleted." << std::endl;
                std::cout << " " << std::endl;
            }
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
                Account::printAccountInformation(account);
            }
        }
    }

    void saveNewBalance(Account account, int id){
        accounts[id] = std::move(account);
    }

    std::string getName(){
        return BankName;
    }

    Account getAccount(int id){
        return accounts[id];
    }

    std::unordered_map<int, Account> getAllAccounts(){
        return accounts;
    }
};

// Admin class

class Admin{
private:
    std::string name;
    std::string password;
public:
    Admin() {
        std::cout << "Enter Admin Name: ";
        std::cin >> name;

        std::cout << "Set Admin Password(KEEP A NOTE OF PASSWORD): ";
        std::cin >> password;
        std::cout << " " << std::endl;
    }

    bool checkPassword(){
        std::string p;
        std::cout <<"Enter admin password: ";
        std::cin >> p;

        if(p == password){
            return true;
        }
        else {
            std::cout <<"Incorrect Password!";
            return false;
        }
    }

    void displayAccounts(Bank& bank){
        bool flag = checkPassword();
        if(flag){
            std::unordered_map<int, Account> mp = bank.getAllAccounts();
            printAllAccounts(mp);
        }
    }

    static void printAllAccounts(const std::unordered_map<int, Account>& accmap){
        for(const auto& i : accmap){
            printAccount(i.first, i.second);
        }
    }

    void findAccount(Bank& bank, int id){
        bool p_flag = checkPassword();
        if(p_flag) {
            bool flag = bank.doesAccountExist(id);
            if (flag) {
                Account acc = bank.getAccount(id);
                std::cout << "Account Found:" << std::endl << std::endl;
                printAccount(id, acc);
            } else {
                std::cout << "Account Not Found!" << std::endl;
            }
        }
    }

    static void printAccount(const int k, Account acc){
        std::cout <<"Account Number:      " << k <<std::endl;
        std::cout <<"Account Holder Name: " << acc.getAccountHolderName() << std::endl;
        std::cout <<"Balance:             " << acc.getBalance() << std::endl;
        std::cout << " " << std::endl;
    }
};


int main(){
    Bank bank = Bank("Bank of Tadiwa");
    Admin admin = Admin();

    int entry;
    int accountNumber;
    bool flag;

    do {
        std::cout << "Welcome to the " << bank.getName() << std::endl;
        std::cout <<" "<<std::endl;
        std::cout << "1. Create a New Account" << std::endl;
        std::cout << "2. Display Account Info" << std::endl;
        std::cout << "3. Deposit Funds" << std::endl;
        std::cout << "4. Withdraw Funds" << std::endl;
        std::cout << "5. Delete Account" << std::endl;
        std::cout << "6. Admin Mode" << std::endl;
        std::cout << "7. Exit" << std::endl;
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
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout <<" "<<std::endl;
                flag = bank.doesAccountExist(accountNumber);
                if(flag) {
                    bank.displayAccountInformation(accountNumber);
                }
                break;
            }
            case 3: {
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout <<" "<<std::endl;
                flag = bank.doesAccountExist(accountNumber);
                if(flag) {
                    Account acc = bank.getAccount(accountNumber);
                    acc.deposit();
                    bank.saveNewBalance(acc, accountNumber);
                }
                break;
            }
            case 4:{
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout <<" "<<std::endl;
                flag = bank.doesAccountExist(accountNumber);
                if(flag) {
                    Account acc = bank.getAccount(accountNumber);
                    acc.withdraw();
                    bank.saveNewBalance(acc, accountNumber);
                }
                break;
            }
            case 5:{
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout <<" "<<std::endl;
                flag = bank.doesAccountExist(accountNumber);
                if(flag) {
                    Account acc = bank.getAccount(accountNumber);
                    bank.deleteAccount(accountNumber);
                }
                break;
            }
            case 6:{
                int adm_entry;
                std::cout << "1. Display Accounts" << std::endl;
                std::cout << "2. Find Account" << std::endl;
                std::cout << "3. Exit Admin Mode" << std::endl << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> adm_entry;
                switch (adm_entry) {
                    case 1:{
                        admin.displayAccounts(bank);
                        break;
                    }
                    case 2:{
                        int id;
                        std::cout <<"Enter Account Number: ";
                        std::cin >> id;
                        admin.findAccount(bank, id);
                        break;
                    }
                    case 3:{
                        break;
                    }
                    default:{
                        std::cout <<"Invalid Entry, try again." << std::endl << std::endl;
                        break;
                    }
                }

            }
            case 7: {
                std::cout <<"Thanks for banking with the " << bank.getName();
                std::cout <<" "<<std::endl;
                break;
            }
            default:{
                std::cout <<"Invalid choice, try again!" << std::endl;
                std::cout <<" "<<std::endl;
            }
        }

    }
    while(entry != 7);

    return 0;
}