# Simple Terminal Banking System

This is a basic terminal-based banking system implemented in C++. It allows users to create accounts, deposit and withdraw funds, delete accounts, and provides an admin mode to display and find accounts.

## Getting Started

To run the program, ensure you have a C++ compiler (C++ 14) installed. You can compile and execute the program using the following steps:

1. **Clone the repository:**
    ```bash
    git clone https://github.com/TDD66/BankSystem.git
    cd BankSystem
    ```

2. **Compile the code:**
    ```bash
    g++ -std=c++14 BankCode.cpp -o banking_system
    ```

3. **Run the program:**
    ```bash
    ./banking_system
    ```

## Features

- **Account Creation:** Users can create new accounts providing their name, receiving an account number and PIN.
- **Deposit and Withdrawal:** Users can deposit and withdraw funds from their accounts.
- **Account Deletion:** Users can delete their accounts after verifying their PIN.
- **Admin Mode:** Provides admin functionalities like displaying all accounts and finding a specific account by ID.

## Usage

Upon running the program, follow the on-screen prompts to navigate through the menu options:

- **1:** Create a New Account
- **2:** Display Account Info
- **3:** Deposit Funds
- **4:** Withdraw Funds
- **5:** Delete Account
- **6:** Admin Mode
- **7:** Exit

## Contributing

Contributions are welcome! If you have any suggestions, enhancements, or bug fixes, feel free to open an issue or create a pull request.

## License

This project is licensed under the GNU General Public License (GNU GPL) - see the [LICENSE](LICENSE) file for details.
