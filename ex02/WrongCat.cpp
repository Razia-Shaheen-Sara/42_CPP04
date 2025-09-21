#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat() //default constructor
{
    this->type = "WrongCat"; //setting type to "WrongCat"
    std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &source) //copy constructor
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = source; 
}
WrongCat::~WrongCat() //destructor
{
    std::cout << "WrongCat destructor called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &source) //copy assignment operator
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    this->type = source.type; //copy type from source to this object
    return *this;
}
void WrongCat::makeSound() const //make sound function: "const" because this function should not modify the object
{
    std::cout << "Meow Meow!" << std::endl;
}
std::string WrongCat::getType() const //get type function
{
    return this->type;
}