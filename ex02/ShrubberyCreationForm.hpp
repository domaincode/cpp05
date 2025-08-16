#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& original);
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& original);



};
#endif