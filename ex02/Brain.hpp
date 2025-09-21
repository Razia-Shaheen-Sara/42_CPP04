#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
class Brain
{
    private:
        std::string ideas[100]; //array of 100 strings to hold ideas
    public:
        Brain(); //default constructor
        Brain(const Brain &source); //copy constructor
        ~Brain(); //destructor
        Brain &operator=(const Brain &source); //copy assignment operator
        void setIdea(int index, const std::string &idea); //set idea at specific index
        std::string getIdea(int index) const; //get idea at specific index
        void printIdea(int index) const; //print idea at specific index
};
#endif