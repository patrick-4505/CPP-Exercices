#include <iostream>
#include <array>
using namespace std;


int main() {

    array<int, 5> grades;
    int max_grade = 0;
    float average_grade;
    
    cout << "Enter grade number 1: ";
    cin >> grades[0];
    int min_grade = grades[0];


    cout << "Enter grade number 2: ";
    cin >> grades[1];

    cout << "Enter grade number 3: ";
    cin >> grades[2];

    cout << "Enter grade number 4: ";
    cin >> grades[3];

    cout << "Enter grade number 5: ";
    cin >> grades[4];

    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] > max_grade) {
            max_grade = grades[i];
        }
        if (grades[i] < min_grade) {
            min_grade = grades[i];
        }

        average_grade += grades[i];
    }

    average_grade =  average_grade /grades.size();

    cout << "Average grade: " << average_grade << endl;
    cout << "Maximum grade: " << max_grade << endl;
    cout << "Minimum grade: " << min_grade << endl;

    return 0;
}
