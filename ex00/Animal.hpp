#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(); //default constructor
		Animal(const Animal &source); //copy constructor
		virtual ~Animal(); //destructor //made virtual to ensure derived class destructors are called explained below
		Animal &operator=(const Animal &source); //copy assignment operator
		virtual void makeSound() const; //const because it doesn't modify the object: derived classes funcs MUST also have const to match
		std::string getType() const; //get type function

};


#endif

//“Polymorphism is when the same function call does different things depending on the actual object it’s called on.”

//// ------------------- Virtual Function -------------------
////A virtual function is a member function in the base class that is always overridden in the derived class.

//// ------------------- Virtual vs Non-Virtual destructor -------------------
//**Virtual destructor → both child and parent destructors run
//**Non-virtual  destructor → only parent runs, child destructor skipped leaving resources allocated in child not freed (memory leak).


//// ------------------- Virtual vs Non-Virtual makeSound() -------------------
//
//BASE CLASS FUNCTION: NOT VIRTUAL
//
// 
// Base object:
// Animal a;
// a.makeSound();  
// ✅ Works fine. Calls Animal::makeSound().
//
//Base pointer to Base object:
// Animal* a = new Animal();
// a->makeSound();
// ✅ Works fine. Calls Animal::makeSound().
//
// Example 2: Direct call to Derived object (NO base pointer/reference)
// Dog d;
// d.makeSound();
// ✅ Works fine. Calls Dog::makeSound().
//
// Base pointer to Derived object:
// Animal* a = new Dog();
// a->makeSound();
// ❌ Calls Animal::makeSound() (wrong).
//
// Base reference to Derived object:
// Animal& a = d;
// a.makeSound();
// ❌ Calls Animal::makeSound() (wrong).
//
// ✅ If makeSound() IS virtual:
//      Calls Dog::makeSound() (correct).
//
//

//When you use a base class pointer or reference to refer to a derived class object, you can call the overridden function in the derived class. This is known as runtime polymorphism.
//**If makeSound() were not virtual, calling it on a base class pointer to a derived class object would invoke the base class version, not the derived class version.	
