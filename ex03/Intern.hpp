#ifndef INTERN_HPP
#define INTERN_HPP


#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        // Intern(std::string name, std::string target);
        Intern(const Intern& original);
        Intern& operator=(const Intern& original);

        AForm* makeForm(std::string name, std::string target);
};

#endif