#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal //inherits from animal
{
    public:
        WrongCat(); //default constructor
        WrongCat(const WrongCat &source); //copy constructor
        ~WrongCat(); //destructor
        WrongCat &operator=(const WrongCat &source); //copy assignment operator
        void makeSound() const; //make sound function
        std::string getType() const; //get type function
};
#endif