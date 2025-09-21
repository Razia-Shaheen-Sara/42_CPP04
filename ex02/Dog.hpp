#ifndef DOG_HPP
#define DOG_HPP
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal //inherits from Animal
{
	private:
		Brain *brain; //pointer to Brain object
	
	public:
		Dog(); //default constructor
		Dog(const Dog &source); //copy constructor
		~Dog(); //destructor
		Dog &operator=(const Dog &source); //copy assignment operator
		
		void makeSound() const; //make sound function
		std::string getType() const; //get type function
		void setBrainIdea(int index, const std::string &idea); //set idea in brain at specific index
		std::string getBrainIdea(int index) const; //get idea from brain at specific index
};

//because brain is a private member of Dog, we need setter and getter functions to access and modify it from outside the class

#endif
