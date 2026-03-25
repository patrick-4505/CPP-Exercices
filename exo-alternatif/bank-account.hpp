#include <iostream>
#include <string>
using namespace std;


class BankAccount {
   private:
    string _owner;
    float _balance;


    public:     
      
       BankAccount(const string& owner, float balance) {
         _owner = owner;
         _balance = balance;
       }

    bool deposit(float amount) {
        if (amount > 0) {
            _balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(float amount) {
        if (amount <= _balance && amount > 0) {
            _balance -= amount;
            return true;
        }
        return false;
    }

    string getOwner() const {
        return _owner;

    }

    float getBalance() const {
        return _balance;
    }

    
     void display() const { 
        cout << "Owner: " << _owner << endl;
        cout << "Balance: " << _balance << endl;
    }



};
