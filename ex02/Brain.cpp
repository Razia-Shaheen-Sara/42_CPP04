#include "Brain.hpp"
#include <iostream>
#include <string>
Brain::Brain() //default constructor
{
    std::cout << "Brain default constructor called" << std::endl;
}
Brain::Brain(const Brain &source) //copy constructor
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = source; 
}
Brain::~Brain() //destructor
{
    std::cout << "Brain destructor called" << std::endl;
}
Brain &Brain::operator=(const Brain &source) //copy assignment operator
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this == &source) //self-assignment check
        return *this;
    for (int i = 0; i < 100; i++) //copy each idea from source to this object
        this->ideas[i] = source.ideas[i];
    return *this;
}
void Brain::setIdea(int index, const std::string &idea) //set idea at specific index
{
    if (index < 0 || index >= 100) //index out of bounds check
    {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    this->ideas[index] = idea; //set idea at specific index
}
std::string Brain::getIdea(int index) const //get idea at specific index
{
    if (index < 0 || index >= 100) //index out of bounds check
    {
        std::cout << "Index out of bounds" << std::endl;
        return "";
    }
    return this->ideas[index]; //return idea at specific index
}

void Brain::printIdea(int index) const 
{
    if (index >= 0 && index < 100)
        std::cout << "Idea[" << index << "]: " << ideas[index] << std::endl;
}