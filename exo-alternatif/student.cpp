#include <iostream>
#include <vector>
#include "student.hpp"

int main() {
    Student student("Alice");

    cout <<"Après avoir ajouter 3 notes : "<<endl;
    student.addGrade(15.0);
    student.addGrade(12.0);
    student.addGrade(18.0);

    student.display();

    cout <<"Après avoir ajouter plus de notes avec un vector : "<<endl;

    std::vector<double> moreGrades = {14.0, 16.0,10.0};
    student.addGrade(moreGrades);

    student.display();
    return 0;
}