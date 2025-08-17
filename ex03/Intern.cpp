#include "Intern.hpp"

 Intern::Intern(){

 }

 Intern::~Intern(){

 }

 Intern::Intern(const Intern& original){ /// remeber

 }

 Intern& Intern::operator=(const Intern& original){

 }

 AForm* Intern::makeForm(std::string name, std::string target){

    std::string names[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
    AForm* ptr;
    int i;

    i = 0;
    while(i < 3 && name != names[i])
        i++;
    switch(name == "Shrubbery Creation"){
        ptr = new ShrubberyCreationForm (target);
    }
    else if(name == "Robotomy Request"){
        ptr = new RobotomyRequestForm (target);
    }
    else if(name == "Presidential Pardon"){
        ptr = new PresidentialPardonForm (target);
    }
    else{
        std::cout << "wrong Format Name\n";
        return nullptr;
    }
    std::cout << "Intern creates " << name << std::endl;
    return ptr;
 }




