#include<iostream>
#include<string>
using namespace std;
struct Account {
    string name;
    int accountno;
    float balance;
};

void createAccount(Account &acc, bool &accountcreated);
void deposit(Account &acc, bool &accountcreated);
void withdraw(Account &acc, bool &accountcreated);
void balance_check(Account &acc, bool &accountcreated);

int main() {
    Account user;
    int choice;
    bool accountcreated=false;
    do {
        cout <<"\n\n---------Simple Bank System---------\n" << endl;
        cout<<"1. Create Bank Account"<<endl;
        cout<<"2. Deposit Money"<<endl;
        cout<<"3. Withdraw Money"<<endl;
        cout<<"4. Check Balance"<<endl;
        cout<<"5. Exit\n";
        cout<<"------------------------------------\n";
        cout << "Enter Your Choice: ";
        cin>>choice;
        switch(choice) {
        case 1:
            createAccount(user, accountcreated);
            break;
        case 2:
            deposit(user, accountcreated);
            break;
        case 3:
            withdraw(user, accountcreated);
            break;
        case 4:
            balance_check(user, accountcreated);
            break;
        case 5:
            cout << "Thank You for using the System" << endl;
            cout << "Visit Again!" << endl;
            break;
        default:
            cout << "Invalid Choice! Try Again\n" << endl;
        }
    }
    while(choice!=5);
    return 0;
}

void createAccount(Account &acc, bool &accountcreated) {
    if(accountcreated) {
        cout << "Account already created! You cannot create another account" << endl;
        return;
    } else {
        cout<<"Enter your name: ";
        cin>>acc.name;
        cout<<"Enter account number: ";
        cin>>acc.accountno;
        while(acc.accountno<=0) {
            cout << "Invalid! Enter Position Account Number: " ;
            cin>>acc.accountno;
        }
        acc.balance=0.0;
        cout << "\nAccount Created Successfully!\n\n" << endl;
        accountcreated= true;
    }
}

void deposit(Account &acc, bool &accountcreated) {
    float amount;
    if(accountcreated) {
        cout<<"Enter Deposit amount: ";
        cin>>amount;
        if(amount>0) {
            acc.balance+=amount;
            cout << "\nDeposit successfully!\n\n" << endl;
        } else {
            cout << "\nInvalid Amount\n\n" << endl;
        }
    } else {
        cout << "\nCreate an account first!" << endl;
    }
}

void withdraw(Account &acc, bool  &accountcreated) {
    float amount;
    if(accountcreated) {
        cout<<"Enter withdrawal Amount: ";
        cin >> amount;
        if(amount>0 && amount<= acc.balance) {
            acc.balance-= amount;
            cout << "Withdrawal successfully!\n\n" << endl;
        } else {
            cout << "Invalid amount and insufficient balance!\n\n" << endl;
        }
    } else {
        cout << "\nCreate an account first!" << endl;
    }
}

void balance_check(Account &acc, bool &accountcreated) {
    if(accountcreated) {
        cout << "Account Holder: " << acc.name<<endl;
        cout<< "Account Number: "<<acc.accountno<<endl;
        cout<<"Current Balance: "<<acc.balance<<endl;
    } else {
        cout << "\nCreate an account first!" << endl;
    }
}

