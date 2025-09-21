#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <string>
#include <iostream>
class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal(); //default constructor
        AAnimal(const AAnimal &source); //copy constructor
        virtual ~AAnimal(); //destructor //made virtual to ensure derived class destructors are called explained below
        AAnimal &operator=(const AAnimal &source); //copy assignment operator
        virtual void makeSound() const = 0; //pure virtual function makes this an abstract class: derived classes funcs MUST also have const to match
        std::string getType() const; //get type function

};
#endif
//Abstract class is a class that cannot be made into an object directly. It can only be used as a base class for other classes.
//You make a class abstract by declaring at least one of its functions as a pure virtual function.
//A pure virtual function is a virtual function that has no implementation in the base class and is declared by assigning 0 to it.
//Any class that contains at least one pure virtual function is considered an abstract class.
//Derived classes must override the pure virtual function to provide an implementation, otherwise they will also be abstract classes.
//Use abstract classes when you want to define a common base for a group of related classes, but you don't want to allow direct objects of the base class to be created.