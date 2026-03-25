#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Student {

    private:
        string _name;
        vector<double> _grades;  
    public:

        Student(const string& name) {  
            _name = name;
        }

        void addGrade(double grade) {
            _grades.push_back(grade);
        }

        void addGrade(const vector<double>& grades) {  
            for (double grade : grades) {
                _grades.push_back(grade);
            }
        }

        double getAverage() const {
            if (_grades.empty()) return 0.0;
            double sum = 0;
            for (double grade : _grades) {
                sum += grade;
            }
            return sum / _grades.size();
        }

        double getHighestGrade() const {
            if (_grades.empty()) return 0.0;
            return *max_element(_grades.begin(), _grades.end());
        }

        double getLowestGrade() const {
            if (_grades.empty()) return 0.0;
            return *min_element(_grades.begin(), _grades.end());
        }


        void display() const {
            cout << "Etudiant : " << _name << endl;
            cout << "Notes    : ";
            for (double grade : _grades) {
                cout << grade << " ";
            }
            cout << endl;
            cout << "Moyenne  : " << getAverage() << endl;
            cout << "Max      : " << getHighestGrade() << endl;
            cout << "Min      : " << getLowestGrade() << endl;
        }
};