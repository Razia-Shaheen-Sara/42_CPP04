#ifndef CAT_HPP
#define CAT_HPP
#include <string>
#include "AAnimal.hpp"

class Cat: public AAnimal //inherits from animal
{	
	private:
		Brain *brain; //pointer to Brain object
	
	public:
		Cat(); //default constructor
		Cat(const Cat &source); //copy constructor
		~Cat(); //destructor
		Cat &operator=(const Cat &source); //copy assignment operator


		void makeSound() const; //make sound function
		std::string getType() const; //get type function
		void setBrainIdea(int index, const std::string &idea); //set idea in brain at specific index
		void getBrainIdea(int index) const; //get idea from brain at specific index
};

#endif
