#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() //default constructor
{
    this->type = "Dog"; //setting type to "Dog"
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &source) //copy constructor
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = source; 
}
Dog::~Dog() //destructor
{
    std::cout << "Dog destructor called" << std::endl;
} 
Dog &Dog::operator=(const Dog &source) //copy assignment operator
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    this->type = source.type; //copy type from source to this object
    return *this;
}

void Dog::makeSound() const //make sound function
{
    std::cout << "Woof Woof!" << std::endl;
}

std::string Dog::getType() const //get type function
{
    return this->type;
}