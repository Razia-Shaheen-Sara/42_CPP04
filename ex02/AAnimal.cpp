#include "AAnimal.hpp"
#include <iostream>
#include <string>
AAnimal::AAnimal(): type("AAnimal") //setting default type to "AAnimal"
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &source) //copy constructor
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = source; 
}

AAnimal::~AAnimal() //destructor
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &source) //copy assignment operator
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    this->type = source.type; //copy type from source to this object
    return *this;
}

std::string AAnimal::getType() const //get type function
{
    return this->type;
}

// Note: makeSound() is a pure virtual function and thus has no implementation here.

void AAnimal::makeSound() const
{
    std::cout << "Abstract Animal sound!" << std::endl;
}