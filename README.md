![Screenshot (159)](https://github.com/mohitsingh67/Bank-Management-Project/assets/117108809/f52885da-79fb-408f-835e-4d36b27d5379)
# Bank-Management-Project-C++
 
Description of the code :
It is a simplified implementation of a banking system in C++. It allows users to create and manage bank accounts, perform transactions like deposits and withdrawals, and modify account details.
The code consists of several classes and functions:

Bank class:

It serves as the base class for the banking system.
Member variables:
dev_name: Stores the names of the developers.
system_time: Stores the current system time.
Member functions:
Bank(): Constructor that initializes the system_time with the current time.
show_dev_info(): Displays the names of the developers.
show_time(): Displays the current system time.
account class:

Derived from the Bank class.
Represents a general bank account.
Member variables:
name: Stores the customer's name.
acc_no: Stores the account number.
Member functions:
get_account(): Prompts the user to enter the account details.
show_account(): Displays the account details.
current_account class:

Derived from the account class.
Represents a current account.
Adds a member variable balance to store the current account balance.
Member functions:
deposit(): Prompts the user to enter an amount to deposit and adds it to the current balance.
withdraw(): Prompts the user to enter an amount to withdraw and subtracts it from the current balance.
delete_account(): Deletes the current account.
modify_account(): Allows the user to modify the account details.
show_balance(): Displays the current account balance.
saving_account class:

Derived from the account class.
Represents a savings account.
Adds a member variable balance to store the savings account balance.
Member functions:
deposit(): Prompts the user to enter an amount to deposit and adds it to the savings balance.
withdraw(): Prompts the user to enter an amount to withdraw and subtracts it from the savings balance.
show_balance(): Displays the savings account balance.
main() function:

Entry point of the program.
Creates objects of the current_account and saving_account classes.
Calls the get_account() function to set the account details for both types of accounts.
Displays a menu of options for the user to select operations like deposit, withdrawal, and modification.
Based on the user's choice, calls the corresponding member functions of the account classes to perform the selected operation.
The program continues to run until the user chooses to exit.
