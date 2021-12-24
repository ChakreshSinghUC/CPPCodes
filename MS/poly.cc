#include <iostream>

using namespace std;
// Base class
class Animal {
public:
  void animalSound() { cout << "The animal makes a sound \n"; }
  Animal(){
      cout << "Animal CONSTRUCTOR\n";
  }
};

// Derived class
class Pig : public Animal {
public:
  void animalSound() { cout << "The pig says: wee wee \n"; }
};

// Derived class
class Dog : public Animal {
public:
  void animalSound() { cout << "The dog says: bow wow \n"; }
  Dog() { cout << "Dog CONSTRUCTOR\n"; }
};

int main() {

  try {
    int age = 15;
    if (age >= 18) {
      cout << "Access granted - you are old enough.";
    } else {
      throw(age);
    }
  } catch (...) {
    cout << "Access denied - You must be at least 18 years old.\n";
    // cout << "Age is: " << myNum;
  }
//   Animal myAnimal;
//   Pig myPig;
//   Dog myDog;

//   myAnimal.animalSound();
//   myPig.animalSound();
//   myDog.animalSound();
//   return 0;
}