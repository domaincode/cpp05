#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("Default", 145, 137)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:AForm(target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
:AForm(o)
{

}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o)
{
    if(this != &o)
        AForm::operator=(o);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

    try{
            if(get_Status() == true && get_gradeToExecute() >= executor.getGrade())
            {
                std::ofstream file(get_Name() + "_shrubbery");
            }
            else
                throw GradeTooLowException();
    }
    catch(std::exception& e)
    {
        std::cout << "catchaa: " << e.what();
    }
}
