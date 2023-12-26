#include <iostream>
#include <iomanip>
using namespace std;

struct bankstatement
{
    char name[50];
    unsigned int accountNumber;
    double currentBalance = 0;
    double creditedAmount;
    double debitedAmount;
} statement;

void openAccount();
void checkBalance();
void deposit();
void withdraw();
void showStatement();
int checkAccountNumber();

void openAccount()
{
    std::cout << "Please provide some information for Opening an Account" << endl;
    std::cout << "\n\t\tEnter your name: ";
    std::cin >> statement.name;
    std::cout << "\n\t\tChoose Account Number: ";
    std::cin >> statement.accountNumber;
std:
    cout << "\n\t\tDeposit Opening Balance: ";
    std::cin >> statement.currentBalance;
    std::cout << statement.name << " your Account is created successfully.\n\t\t Press any key to continue." << endl;
}

int checkAccountNumber()
{
    int enteredAccountNumber;
    std::cout << "Enter your Account Number: ";
    std::cin >> enteredAccountNumber;
    if (statement.accountNumber == enteredAccountNumber)
    {
        return true;
    }
    else
    {
        std::cout << "Invalid Account Numner. Please enter a valid Account Number.\n\t\t Press any key to continue." << endl;
    }
}

void checkBalance()
{
    int check = checkAccountNumber();
    if (check == true)
    {
        std::cout << std::fixed << std::setprecision(2) << "Your current balance is Rs." << statement.currentBalance << "\n\t\t Press any key to continue." << endl;
    }
}

void deposit()
{
    int check = checkAccountNumber();
    if (check == true)
    {
        std::cout << "Enter the amount you want to deposit: ";
        std::cin >> statement.creditedAmount;
        statement.currentBalance += statement.creditedAmount;
        std::cout << std::fixed << std::setprecision(2) << "Your new balance is Rs. " << statement.currentBalance << ".\n\t\t Press any key to continue." << endl;
    }
}

void withdraw()
{
    int check = checkAccountNumber();
    if (check == true)
    {
        std::cout << "Enter the amount you want to withdraw: ";
        std::cin >> statement.debitedAmount;
        if (statement.debitedAmount > statement.currentBalance)
        {
            std::cout << "Insuffecient balance.\n\t\t Press any key to continue." << endl;
        }
        else
        {
            statement.currentBalance -= statement.debitedAmount;
            std::cout << std::fixed << std::setprecision(2) << "Your new balance is Rs. " << statement.currentBalance << "\n\t\t Press any key to continue." << endl;
        }
    }
}

void showStatement()
{
    std::cout << "This feature has not been added yet, Please wait untill the next update.\n\t\t Press any key to continue." << endl;
}

int main()
{
    char ch;
    int num;
    do
    {
        system("CLS");

        std::cout << "\t\tDevpriya Bank\n\n\t\t";

        std::cout << "::MAIN MENU::\n";
        std::cout << "\n\t\t1. Open Account";
        std::cout << "\n\t\t2. Make A Deposit";
        std::cout << "\n\t\t3. Make A Withdrawal";
        std::cout << "\n\t\t4. View Balance";
        std::cout << "\n\t\t5. View Transection History";
        std::cout << "\n\t\t6. EXIT";
        std::cout << "\n\n\t\tSelect Your Option (1-6): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            system("CLS");
            openAccount();
            break;
        case '2':
            system("CLS");
            deposit();
            break;
        case '3':
            system("CLS");
            withdraw();
            break;
        case '4':
            system("CLS");
            checkBalance();
            break;
        case '5':
            system("CLS");
            showStatement();
            break;
        case '6':
            system("CLS");
            std::cout << "\n\n\tThankyou for working with Devpriya Bank." << endl;
            break;
        default:
            std::cout << "\a Enter a valid option.\n\n\n";
        }
        cin.ignore();
        cin.get();
    } while (ch != '6');

    return 0;
}