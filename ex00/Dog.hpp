#ifndef DOG_HPP
#define DOG_HPP
#include <string>
#include "Animal.hpp"

class Dog: public Animal //inherits from Animal
{
	public:
		Dog(); //default constructor
		Dog(const Dog &source); //copy constructor
		~Dog(); //destructor
		Dog &operator=(const Dog &source); //copy assignment operator
		void makeSound() const; //make sound function
		std::string getType() const; //get type function
};


#endif
