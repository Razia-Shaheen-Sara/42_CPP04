#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(): type("Animal") //setting default type to "Animal"
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &source) //copy constructor
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = source; 
}

Animal::~Animal() //destructor
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &source) //copy assignment operator
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    this->type = source.type; //copy type from source to this object
    return *this;
}

void Animal::makeSound() const 
{
    std::cout << "Animal sound!" << std::endl;
}

std::string Animal::getType() const //get type function
{
    return this->type;
}


