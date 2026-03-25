#include <iostream>
#include "bank-account.hpp"
using namespace std;

int main(){
     
   BankAccount account("Alice", 500);
    account.display();

    cout << endl;

    cout << "Depositing 500..." << endl;
    if (account.deposit(500))
        cout << "Deposit successful!" << endl;
    else
        cout << "We can't deposit that amount." << endl;
    account.display();

    cout << endl;

    cout << "Withdrawing 200..." << endl;
    if (account.withdraw(200))
        cout << "Withdrawal successful!" << endl;
    else
        cout << "Withdrawal failed!" << endl;
    account.display();

    cout << endl;

    cout << "Trying to withdraw 2000 ..." << endl;
    if (account.withdraw(2000))
        cout << "Withdrawal successful!" << endl;
    else
        cout << "Withdrawal failed!" << endl;
    account.display();


}