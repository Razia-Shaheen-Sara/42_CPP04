#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>  

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(); //default constructor
        WrongAnimal(const WrongAnimal &source); //copy constructor
        ~WrongAnimal(); //destructor
        WrongAnimal &operator=(const WrongAnimal &source); //copy assignment operator
        void makeSound() const; //make sound function
        std::string getType() const; //get type function

};
#endif