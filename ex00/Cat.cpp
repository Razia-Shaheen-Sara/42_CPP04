#include "Animal.hpp"
#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat() //default constructor
{
    this->type = "Cat"; //setting type to "Cat"
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &source) //copy constructor
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = source; 
}
Cat::~Cat() //destructor
{
    std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &source) //copy assignment operator
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    this->type = source.type; //copy type from source to this object
    return *this;
}
void Cat::makeSound() const //make sound function: "const" because this function should not modify the object
{
    std::cout << "Meow Meow!" << std::endl;
}
std::string Cat::getType() const //get type function
{
    return this->type;
}