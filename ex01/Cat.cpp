#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat() //default constructor
{
    this->type = "Cat"; //setting type to "Cat"
    this->brain = new Brain(); //allocate memory for Brain object
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &source) //copy constructor
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = source.type; //copy type from source to this object
    this->brain = new Brain(*source.brain); //deep copy of Brain object opposed to shallow copy (this->brain = source.brain)
}

Cat::~Cat() //destructor
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain; //free allocated memory for Brain object
}

Cat &Cat::operator=(const Cat &source) //copy assignment operator
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    this->type = source.type; //copy type from source to this object
    delete this->brain; //free current object's (this->brain) old brain to make space for new brain from source
    this->brain = new Brain(*source.brain); //deep copy of Brain object opposed to shallow copy (this->brain = source.brain)
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

void Cat::setBrainIdea(int index, const std::string &idea) //set idea in brain at specific index
{
    this->brain->setIdea(index, idea); //use Brain's setIdea function to set idea at specific index
}

void Cat::getBrainIdea(int index) const //get idea from brain at specific index
{
    std::cout << this->brain->getIdea(index) << std::endl; //use Brain's getIdea function to get idea at specific index
}


//--------- DEEP COPY VS SHALLOW COPY ---------//

// Shallow Copy: 
// source and destination objects are basically two pointers pointing to the same memory location.
// So, if one object is modified, the other object gets modified as well.
// If one object is deleted, it's dependent object gets deleted as well leaving the other left with a dangling pointer.
// Dog1.brain ---> Brain object <--- Dog2.brain
// If Dog1 is deleted:
// brain object is deleted
// Dog2.brain ---> ❌ freed memory (dangling pointer)

// Deep Copy: 
// source and dest. object gets their own copy of the data, so they can be modified or deleted independently without affecting each other.
// In this Cat class, we use deep copy for the Brain object to ensure each Cat has its own Brain instance.
// Cat1.brain ---> Brain object for cat1
// Cat2.brain ---> Brain object for cat2 by having a separate memory allocation using new Brain(*source.brain);
