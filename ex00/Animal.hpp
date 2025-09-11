#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(); //default constructor
		Animal(const Animal &source); //copy constructor
		virtual ~Animal(); //destructor
		Animal &operator=(const Animal &source); //copy assignment operator
};

class Dog: public Animal //inherits from Animal
{
	public:
};

class Cat: public Animal //inherits from animal
{	

}

#endif