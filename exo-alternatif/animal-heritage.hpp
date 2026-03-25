using namespace std;
#include <string>

class Animal {
   
   protected:
       string _name;

   public: 
       Animal(const string& name) {
           _name = name;
       }


       string getName() const {
           return _name;
       }


       string makeSound() const {
           return "Some sound";
       }

    
   
};

class Dog : public Animal {

};

class Cat : public Animal {

};