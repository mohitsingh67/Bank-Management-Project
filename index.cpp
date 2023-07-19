#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include<math.h>
using namespace std;

class Bank {
public:
    void showtime() {
        time_t currentTime = time(0);
        string timeString = ctime(&currentTime);
        cout << " " << timeString;
    }
    void about()
    {
    cout<<"\n\n\t\t\t\t\tGuided By - Dr.Nikhlesh Pathik Sir";
    cout << "\n\n\n\t\t\t\t\t ----------------------------------" << endl;
    cout << "\t\t\t\t\t Developed By - 1. Mohit Singh" << endl;
    cout << "\t\t\t\t\t              - 2. Vishrut Dakare" <<endl;
    cout << "\t\t\t\t\t ----------------------------------" <<endl;
	}
};
///////////////////////////////////////////////////////////////////////////////////////
class account : public Bank {
public:
    string name;
    int accno;

public:
    void getAccountDetails() {
        cout << "\n\n\t\t\t\t\t Enter Customer Name : ";
        cin >> name;
        cout << "\t\t\t\t\t Enter Account Number  : ";
        cin >> accno;
       
    }

    void displayDetails() {
        cout << "\n\n\t\t\t\t\t Customer Name : " << name;
        cout << "\n\t\t\t\t\t Account Number  : " << accno;
      
    }
};
//////////////////////////////////////////////////////////////////////////////////////
class current_account : public account {
private:
    float balance;
    bool isDeleted; 
public:
    current_account()               //constructor
    {
       isDeleted = false;
    }
    void c_display() {
        cout << "\n\t\t\t\t\tBalance :Rs" << balance;
    }

    void c_deposit() {
        float deposit;
        cout << "\n\t\t\t\t\t Enter amount to Deposit :  ";
        cin >> deposit;
        balance = balance + deposit;
    }

    void c_withdraw() {
        float withdraw;
        cout << "\n\n\t\t\t\t\t Balance :Rs " << balance;
        cout << "\n\t\t\t\t\t Enter amount to be withdrawn :";
        cin >> withdraw;
        if (balance > 1000) {
            balance = balance - withdraw;
            cout << "\n\t\t\t\t\t Balance Amount After Withdraw: " << balance;
        } else {
            cout << "\n\t\t\t\t\t Insufficient Balance";
        }
    }

    void c_deleteAccount() {
        // Reset the account details and balance
        name = "";
        accno = 0;
        balance = 0;
        isDeleted = true;
    }

    void c_modifyAccount() {
        cout << "\n\n\t\t\t\t\t Enter New Customer Name: ";
        cin >> name;
        cout << "\t\t\t\t\t Enter New Account Number: ";
        cin >> accno;
        cout << "\n\t\t\t\t\t Account Modified Successfully!";
    }
};
////////////////////////////////////////////////////////////////////////////////////////
class saving_account : public account {
private:
    float sav_balance;
    bool isDeleted; // Flag to indicate if the account is deleted

public:
    saving_account() //constructor
    {
        isDeleted = false;
    }
    void s_display() {
        cout << "\n\t\t\t\t\t Balance :  " << sav_balance;
    }

    void s_deposit() {
        float deposit, interest;
        cout << "\n\n\n\t\t\t\t\t Enter amount to Deposit :Rs  ";
        cin >> deposit;
        sav_balance = sav_balance + deposit;
        interest = (sav_balance * 2) / 100;
        sav_balance = sav_balance + interest;
    }

    void s_withdraw() {
        float withdraw;
        cout << "\n\t\t\t\t\t Balance :- " << sav_balance;
        cout << "\n\t\t\t\t\t Enter amount to be withdrawn : ";
        cin >> withdraw;
        if (sav_balance > 500) {
            sav_balance = sav_balance - withdraw;
            cout << "\n\t\t\t\t\t Balance Amount After Withdraw: " << sav_balance;
        } else {
            cout << "\n\t\t\t\t\t Insufficient Balance";
        }
    }

    void s_deleteAccount() {
        // Reset the account details and balance
        name = "";
        accno = 0;
        sav_balance = 0;
        isDeleted = true;
    }

    void s_modifyAccount() {
        cout << "\n\n\t\t\t\t\t Enter New Customer Name: ";
        cin >> name;
        cout << "\t\t\t\t\t Enter New Account Number: ";
        cin >> accno;
        cout << "\n\t\t\t\t\t Account Modified Successfully!";
    }
};
/////////////////////////////////////////////////////////////////////////

class fixed_deposit:public account
{
	protected:
    string accountnumber;
    double balance;
    double interestRate,amount;
    double principal,rate,interest,maturity,depositamount, withdrawamount;
    int time;

public:
	
	
	void getdata() {
        cout << "Account Number: ";
        cin >> accountnumber;
        cout << "Balance: ";
        cin >> balance;
        cout<<"entering amount";
        cin>>amount;
        cout << "Interest Rate (%): ";
        cin >> interestRate;
    }

    void displayAccount() {
        cout << "Account Number: " << accountnumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

    void deposit(double amount) {
    	
        balance += amount;
        cout << "Deposit of " << amount << " successful." << endl;
    }

    void withdraw(double amount) {
    	
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal of " << amount << " successful." << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    void calculateInterest() {
        double interest = (balance * interestRate) / 100;
        balance += interest;
        cout << "Interest calculated and added to the account." << endl;
    }
			
         };

///////////////////////////////////////////////////////////////////////////

class loan
{
protected:
    string name;
    double loanamt, interestrate, interestMonthlyRate, totalInterestPaid, finalTotalPaid, monthlyPayments;
    int years;
    float irate;
    int months;

public:
    void getloandata()
    {
        cout << "\nTotal loan amount: Rs";
        cin >> loanamt;
        cout << "\nLoan term (in years): ";
        cin >> years;
        cout << "\nInterest Rate per year: ";
        cin >> interestrate;
        
        interestMonthlyRate = interestrate / 12 / 100; // Monthly interest rate
        months = years * 12;
        monthlyPayments = (loanamt * pow(interestMonthlyRate + 1, months) * interestMonthlyRate) / (pow(interestMonthlyRate + 1, months) - 1);
        finalTotalPaid = monthlyPayments * months;
        totalInterestPaid = finalTotalPaid - loanamt;
    }

    void showloan()
    {
      
        cout << "   Total Loan Amount: Rs" << loanamt << endl << endl;
        cout << "   You will have " << months << " total payments." << endl << endl;
        cout << "   Your monthly payment is Rs" << monthlyPayments << endl << endl;
        cout << "   The total amount paid back is Rs" << finalTotalPaid << endl << endl;
        cout << "   Your total interest paid is Rs" << totalInterestPaid << endl << endl;
     
    }
};

///////////////////////////////////////////////////////////////////////////
int main() {
    system("color B");
    Bank obj;
    account a1;
     current_account c;
    saving_account s;
   vector<current_account> currentAccounts;
    vector<saving_account> savingAccounts;
    fixed_deposit f1;
    loan l;


    cout << "\n\n\t\t\t\t\t ***********************************" << endl;
    cout << "\t\t\t\t\t  Welcome to Bank Management System" << endl;
    cout << "\t\t\t\t\t ***********************************" << endl;
    
    obj.showtime();

    cout<<"\n\n\n\t\t\t\t\t\t   [1] Create Account";
    cout<<"\n\n\n\t\t\t\t\t\t   [2] Loan Calculator";
    cout<<"\n\n\n\t\t\t\t\t\t   [3] About Us";
    
    int choice;
    cout << "\n\n\n\n\t\t\t\t\t Enter Your choice: ";
    cin >> choice;
    
    while (true) {
        switch (choice) {
            case 1: {
                system("cls");
                char type;
                cout<<"\n\n\t\t\t\t\t [1]. Saving Account";
                cout<<"\n\n\t\t\t\t\t [2]. Current Account";
                cout<<"\n\n\t\t\t\t\t [3]. Fixed Deposit Account";
                
                cout<<"\n\n\t\t\t\t\t Enter Your Choice :";
                cin >> type;
                int choice1;

                if (type == '1' || type == 'a') {
                    while (true) {
                       
                       cout << "\n\n\t\t\t\t\t 1) Add Account Details";
                       cout << "\n\t\t\t\t\t 2) Deposit Amount";
                       cout << "\n\t\t\t\t\t 3) Withdraw Amount";
                       cout << "\n\t\t\t\t\t 4) Display Balance";
                       cout << "\n\t\t\t\t\t 5) Display Account Details";
                       cout << "\n\t\t\t\t\t 6) Modify Account";
                       //cout << "\n\t\t\t\t\t 7) Delete Account";
                       cout << "\n\t\t\t\t\t 7) Exit";
                       cout << "\n\n\t\t\t\t\t Enter your choice: ";
                       cin >> choice1;

                        switch (choice1) {
                            case 1:
                                system("cls");
                                s.getAccountDetails();
                                cout<<"\t\t\t\t\t Your account is created at:" ;
                                s.showtime();
                                savingAccounts.push_back(s);
                                break;
                            case 2:
                                {
								system("cls");
                                int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;
                                
                                bool found = false;
                                for (saving_account& s : savingAccounts)   //vector
								 {
                                    if (s.accno == accountNumber) 
									{
                                        s.s_deposit();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                            }
                                break;
                            case 3:
                                {
								system("cls");
                                 int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;
                                                           
                                bool found = false;
                                for (saving_account& s : savingAccounts) {
                                    if (s.accno == accountNumber) {
                                        s.s_withdraw();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                            }
                                break;
                                
                            case 4:
							{
							
                                system("cls");
                                int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;
                                
                                bool found = false;
                                for (saving_account& s : savingAccounts) {
                                    if (s.accno == accountNumber) {
                                        s.s_display();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                                break;
   							}
                                break;
                            case 5:
                            {
							   system("cls");
                                int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;

                                bool found = false;
                                for (saving_account& s : savingAccounts) {
                                    if (s.accno == accountNumber) {
                                        s.displayDetails();
                                        cout<<"\n\t\t\t\t\t Type of Account : S";
                                        s.s_display();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                            }
							    break;
                            case 6:
                            {
							  system("cls");
                                 int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;

                                bool found = false;
                                for (saving_account& s : savingAccounts) {
                                    if (s.accno == accountNumber) {
                                        s.s_modifyAccount();
                                        s.showtime();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                            } 
							    break;
                     /*       case 7:
                            {			
                                system("cls");
                                s.s_deleteAccount();
                                s.showtime();
                        }
							    break;*/
                            case 7:
                                return 0;  // Exit the program
                            default:
                                cout << "\n\t\t\t\t\t Invalid choice. Please try again.";
                        }
                    }
                } 
///////////////////////////////////////////////////////////////////////////////////////////////////				
				else if(type =='3' ||type=='c')
                {
                	while(true)
                	{
                	cout << "\n\n\n\t\t\t\t\t You have Choosed a Fixed deposit Account";
                       cout << "\n\n\t\t\t\t\t 1) Add Account Details";
                       cout << "\n\t\t\t\t\t 2) Display Account";
                       cout << "\n\t\t\t\t\t 3) Desopit in Account";
                       cout << "\n\t\t\t\t\t 4) widthdraw from Account";
                       cout << "\n\t\t\t\t\t 5) Calculate";
                       cout << "\n\t\t\t\t\t 6) Exit";
                       cout << "\n\n\t\t\t\t\t Enter your choice: ";
                       cin >> choice1;

                        switch (choice1) {                            
						       
							    case 1:
                                system("cls");
                                f1.getdata();
                                cout<<"\t\t\t\t\t Your account is created at:" ;
                                s.showtime();
                              break;
                        
						      case 2:
                        
                              	system("cls");
                              	f1.displayAccount();
                              	break ;
                        
						      	case 3:
                              	system("cls");
                              	double depositamount, withdrawamount;
                              	cout << "Enter the amount to deposit: ";
                                cin >> depositamount;
                              	f1.deposit(depositamount);;                              			
                              	break;
                        
						      	case 4:
                              	system("cls");
                              	cout << "Enter the amount to withdraw: ";
                                cin >> withdrawamount;
								  f1.withdraw(withdrawamount);
						
								  case 5:
								system("cls");
								  f1.calculateInterest();
								  break;
														  	
                              	case 6:
                              system("cls");
                              return 0;
                              	break;
                              	
                            default:
                                cout << "\n\t\t\t\t\t Invalid choice!";              	
				       } 
			        }
			    }
					
///////////////////////////////////////////////////////////////////////////////////////////					
				
				else if (type == '2' || type == 'b') {
                    while (true) {
                        
                        cout << "\n\n\t\t\t\t\t 1) Add Account Details";
                        cout << "\n\t\t\t\t\t 2) Deposit Amount";
                        cout << "\n\t\t\t\t\t 3) Withdraw Amount";
                        cout << "\n\t\t\t\t\t 4) Display Balance";
                        cout << "\n\t\t\t\t\t 5) Display Account Details";
                        cout << "\n\t\t\t\t\t 6) Modify Account";
                       // cout << "\n\t\t\t\t\t 7) Delete Account";
                        cout << "\n\t\t\t\t\t 7) Exit";
                        cout << "\n\n\t\t\t\t\t Enter your choice: ";
                        cin >> choice1;

                        switch (choice1) {
                            case 1:
                                system("cls");
                                c.getAccountDetails();
                                cout<<"\t\t\t\t\t Your account is created at:" ;
                                c.showtime();
                                currentAccounts.push_back(c);
                                break;
                            case 2:
                            {
							
                                system("cls");
                                int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;
                                
                                bool found = false;
                                for (current_account& c : currentAccounts) {
                                    if (c.accno == accountNumber) {
                                        c.c_deposit();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                            }
                                break;
                            case 3:
                           {
							    system("cls");
							     int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;
                                
                               bool found = false;
							    for (current_account& c : currentAccounts) {
                                    if (c.accno == accountNumber) {
                                        c.c_withdraw();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                           }
						        break;
                            case 4:
                            {
							  system("cls");
                             int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;
                                
                                bool found = false;
                                for (current_account& c : currentAccounts) {
                                    if (c.accno == accountNumber) {
                                        c.c_display();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                            }
							    break;
                            case 5:
                            {
							
                                system("cls");
                                
                                int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;
                                
								 bool found = false;
                                for (current_account& c : currentAccounts) {
                                    if (c.accno == accountNumber) {
                                        c.displayDetails();
                                        cout<<"\n\t\t\t\t\t Type of Account : C";
                                        c.c_display();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
						    }
							    break;
                            case 6:
                            {
							    system("cls");
                             int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;
                             
							 bool found = false;
                                for (current_account& c : currentAccounts) {
                                    if (c.accno == accountNumber) {
                                        c.c_modifyAccount();
                                        c.showtime();
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }   
      						}
							    break;
                           /*case 7:
                            {
                                system("cls");
                                int accountNumber;
                                cout << "\n\t\t\t\t\t Enter Account Number: ";
                                cin >> accountNumber;

                                bool found = false;
                                for (auto it = savingAccounts.begin(); it != savingAccounts.end(); ++it) {
                                    if ((*it).accno == accountNumber) {
                                    	c.c_deleteAccount();
                                        found = true;
                                        break;
                                    }
                                }
                                if (found) {
                                    cout << "\n\t\t\t\t\t Account deleted successfully!";
                                } else {
                                    cout << "\n\t\t\t\t\t Account not found!";
                                }
                                
                            }
							  break;
							  */
                            case 7:
                                return 0;  // Exit the program
                            default:
                                cout << "\n\t\t\t\t\t Invalid choice. Please try again.";
                        }
                    }
                } else {
                cout << "\n\t\t\t\t\t Invalid account type. Please try again.";
                }
                break;
            }
            
		    case 2:
///////////////////////////////////////////////////////////////////////////////////////////////////		    	
		    	 system("cls");
		    	{
		    		
				  
    
		    	char yes;
    const int loanInformation = 1, seeLoanInfo = 2, exitProgram = 3;
    int pickAChoice;
   do {
	
				cout << "Main Menu\n\n"
             << "1. Enter loan information.\n"
             << "2. View loan results.\n"
             << "3. Exit\n\n"
             << "Select an option: ";
             cin >> pickAChoice;
               while (pickAChoice < loanInformation || pickAChoice > exitProgram)
        {	
            cout << "Invalid selection. Please renter choice 1, 2 or 3: ";
            cin >> pickAChoice;
        }
            if (pickAChoice == 1)
            {
            	system("cls");
            	l.getloandata();
			}
			 if(pickAChoice == 2)
			{
				system("cls");
				 l.showloan();
			}
		
			
	}while (pickAChoice != exitProgram);
    system("pause");
	
}
	      break;
	
///////////////////////////////////////////////////////////////////////////////////////////////////                
            case 3:	
            
                system("cls");
                obj.about();
                break;
            default:
                cout << "\n\t\t\t\t\t Invalid choice. Please try again.";
        }

        // Ask if the user wants to continue or exit
        char continueChoice;
        cout << "\n\n\t\t\t\t\t Do you want to continue (Y/N)? ";
        cin >> continueChoice;

        if (continueChoice == 'N' || continueChoice == 'n') {
            return 0;  // Exit the program
        } else {
            system("cls");
            cout << "\n\n\t\t\t\t\t *******************************" << std::endl;
            cout << "\t\t\t\t\t Welcome to Bank Management System" << std::endl;
            cout << "\t\t\t\t\t ***********************************" << std::endl;
            
            obj.showtime();

            cout<< "\n\n\n\t\t\t\t\t\t   [1] Create Account";
            cout<< "\n\n\n\t\t\t\t\t\t   [2] Loan Calculator ";
            cout<< "\n\n\n\t\t\t\t\t\t   [3] About Us";

            cout << "\n\n\n\n\t\t\t\t\t Enter Your choice: ";
            cin >> choice;
        }
    }

    return 0;
}