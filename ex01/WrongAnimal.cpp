#include "WrongAnimal.hpp"
#include <iostream>
#include <string>


WrongAnimal::WrongAnimal(): type("WrongAnimal") //setting default type to "WrongAnimal"
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &source) //copy constructor
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = source; 
}
WrongAnimal::~WrongAnimal() //destructor
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &source) //copy assignment operator
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    this->type = source.type; //copy type from source to this object
    return *this;
}
void WrongAnimal::makeSound() const //make sound function
{
    std::cout << "WrongAnimal sound!" << std::endl;
}
std::string WrongAnimal::getType() const //get type function
{
    return this->type;
}