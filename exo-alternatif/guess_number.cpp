#include <iostream>
#include <ctime> 
using namespace std;


int main() {

    srand(time(0));
    int number_to_guess = rand() % 101;
    int attempt = 0;
    int user_guess;

    cout << "Enter the number to guess: ";
    cin >> user_guess;


    if (user_guess < number_to_guess) {
            cout << "Higher !" << endl;
            attempt++;

            while (user_guess != number_to_guess) {

              cout << "Enter the number to guess: ";
              cin >> user_guess;

              if (user_guess < number_to_guess) {
                cout << "Higher !" << endl;
         
            } else if (user_guess > number_to_guess) {
            cout << "Lower !" << endl;

        }

              attempt++;


       }
         cout << "Congratulations! You guessed the number at the " << attempt << " try!" << endl;

    
    } else if (user_guess > number_to_guess) {
            cout << "Lower !" << endl;
            attempt++;

            while (user_guess != number_to_guess) {

             cout << "Enter the number to guess: ";
             cin >> user_guess;

             if (user_guess < number_to_guess) {
               cout << "Higher !" << endl;
        
            }    else if (user_guess > number_to_guess) {
            cout << "Lower !" << endl;
        }

             attempt++;

       }

       cout << "Congratulations! You guessed the number at the " << attempt << " try!" << endl;
        }


    else { 
        cout << "Congratulations! You guessed the number at the first try!" << endl;
    }
       
    

    return 0;
}