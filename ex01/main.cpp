#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "---------TEST FROM SUBJECT: BRAIN CREATION AND DESTRUCTION---------" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    delete j;//should not create a leak
    delete i;

    std::cout << "---------TEST FOR VIRTUAL DESTRUCTION ---------" << std::endl;

    // TEST PURPOSE:
    // Store Dogs and Cats as Animal* to check virtual destructors.
    // If Animal’s destructor isn’t virtual, only Animal’s dtor runs → memory leaks.
    // If virtual, Dog/Cat dtors + Animal dtor both run  → safe cleanup.


    const int size = 4;
    const Animal* animals[size];

    // First half Dogs, second half Cats
    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    // Cleanup
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "---------TEST FOR DEEP COPY ---------" << std::endl;

    Dog dog1; //default constructor
    dog1.setBrainIdea(0, "Chase the cat");
    Dog dog2 = dog1;  // copy constructor deep copy
    std::cout << "Dog1 idea: " << dog1.getBrainIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrainIdea(0) << std::endl;
    dog2.setBrainIdea(0, "Fetch the ball");
    std::cout << "After modifying Dog2's idea:" << std::endl;
    std::cout << "Dog1 idea: " << dog1.getBrainIdea(0) << std::endl; //should remain "Chase the cat"
    std::cout << "Dog2 idea: " << dog2.getBrainIdea(0) << std::endl; //should be "Fetch the ball"

    //assignment operator deep copy test
    Cat cat1; //default constructor
    cat1.setBrainIdea(0, "Climb the tree");
    Cat cat2;
    cat2 = cat1;  // deep copy via assignment operator of an already existing object
    //here assignment operator will DESTROY cat2's existing brain and allocate a new brain copied from cat1
    //will be in output
    std::cout << "Cat1 idea: ";
    cat1.getBrainIdea(0); //should be "Climb the tree"
    std::cout << "Cat2 idea: ";
    cat2.getBrainIdea(0); //should be "Climb the tree"
    cat2.setBrainIdea(0, "Scratch the sofa");
    std::cout << "After modifying Cat2's idea:" << std::endl;
    std::cout << "Cat1 idea: ";
    cat1.getBrainIdea(0); //should remain "Climb the tree"
    std::cout << "Cat2 idea: ";
    cat2.getBrainIdea(0); //should be "Scratch the sofa"
    return 0; 
}