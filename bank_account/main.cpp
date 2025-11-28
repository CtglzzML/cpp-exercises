#include <iostream>

// Creamos la clase Bank account con sus atributos y metodos
class BankAccount {

    // Balance privado
private:
    double balance = 0;

    // Metodos publicos
public:

    // Deposit funciton
    void deposit(double amount) {
        if (amount <=0) {
            throw std::runtime_error("Amount must be positive!"); // Manejamos los errores
        }
        balance += amount;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::runtime_error("Enter a positive number!");
        }
        if (amount > balance) {
            throw std::runtime_error("Not enough balance!");
        }
        balance -= amount;
    }

    // Display function
    void display() {
        std::cout << "Account balance: " << balance << " $" << std::endl;
    }
};

// Programa principal
int main() {
    BankAccount account;
    std::cout << "*** Welcome to DNB bank ***" << std::endl;
    // Loop para hacer el programa
    while (true) {
        std::cout << "\n----- MENU -----" << std::endl;
        int option;
        std::cout << "\t1. Show balance." << std::endl;
        std::cout << "\t2. Deposit money." << std::endl;
        std::cout << "\t3. Withdraw money." << std::endl;
        std::cout << "\t4. Exit." << std::endl;
        std::cout << "Select an option: ";
        std::cin >> option;

        if (option == 1) {
            account.display();
        }
        else if (option == 2) {
            try {
                std::cout << "\nAmount to deposit: ";
                double depo;
                std::cin >> depo;
                account.deposit(depo);
                std::cout << depo << " $ added to account succesfully!" << std::endl;
            } catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }

        }
        else if (option == 3) {
            try {
                std::cout << "\nAmount to withdraw: ";
                double with;
                std::cin >> with;
                account.withdraw(with);
                std::cout << with << " $ has been removed from your account!" << std::endl;
            } catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else if (option == 4) {
            break;
        }
        else
            std::cout << "Invalid option, try again." << std::endl;
    }
    return 0;
}
