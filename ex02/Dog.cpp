#include "AAnimal.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() //default constructor
{
    this->type = "Dog"; //setting type to "Dog"
    this->brain = new Brain(); //allocate memory for Brain object
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &source) //copy constructor
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = source.type;//copy type (non dynamic attribute) from source to this object
    this->brain = new Brain(*source.brain); //deep copy of dynamic attribute
}

Dog::~Dog() //destructor
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain; //free allocated memory for Brain object
}

Dog &Dog::operator=(const Dog &source) //copy assignment operator
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    this->type = source.type; //copy type from source to this object
    delete this->brain; //free current object's (this->brain) old brain to make space for new brain from source
    this->brain = new Brain(*source.brain); //deep copy of Brain (using it's copy const.) opposed to shallow copy (this->brain = source.brain)
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

void Dog::setBrainIdea(int index, const std::string &idea) //set idea in brain at specific index
{
    this->brain->setIdea(index, idea); //use Brain's setIdea function to set idea at specific index
}

std::string Dog::getBrainIdea(int index) const //get idea from brain at specific index
{
    return this->brain->getIdea(index); //use Brain's getIdea function to get idea at specific index
}
