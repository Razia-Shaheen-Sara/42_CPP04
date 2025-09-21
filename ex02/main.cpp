#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() 
{
    ////This should FAIL to compile because AAnimal is abstract and abstract classes cannot make objects
    //The only way to use an abstract class is to inherit from it and implement the pure virtual functions in the derived class
    //AAnimal a;

    const AAnimal* j = new Dog();  // OK
    const AAnimal* i = new Cat();  // OK

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;
    return 0;
}
