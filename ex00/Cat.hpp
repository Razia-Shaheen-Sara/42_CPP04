#ifndef CAT_HPP
#define CAT_HPP
#include <string>
#include "Animal.hpp"

class Cat: public Animal //inherits from animal
{	
	public:
		Cat(); //default constructor
		Cat(const Cat &source); //copy constructor
		~Cat(); //destructor
		Cat &operator=(const Cat &source); //copy assignment operator
		void makeSound() const; //make sound function
		std::string getType() const; //get type function
};

#endif
