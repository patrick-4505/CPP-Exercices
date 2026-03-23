#include <iostream>
using namespace std;


int main() {

    int num;
    int num2;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter until which number you want the multiplication table: ";
    cin >> num2;

    for (int i = 1; i <= num2; i++) {
        cout << num << " * " << i << " = " << num * i << endl;
    }


    return 0;
}