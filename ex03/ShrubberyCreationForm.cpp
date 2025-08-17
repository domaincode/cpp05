#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("Default", 145, 137), target("Default")
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:AForm("Shrubbery Creation", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
:AForm(o), target(o.target)
{

}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o)
{
    if(this != &o)
    {
        AForm::operator=(o);
        target = o.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

    if(get_Status() == false)
        throw NotSigned();
    if(get_gradeToExecute() >= executor.getGrade())
    {
                std::ofstream file((target + "_shrubbery").c_str());
                if(file.is_open() == false)
                    throw OpenFailed();
                file << "   ^\n  ^^^\n ^^^^^\n   |\n";
                file.close();
    }
    else
        throw GradeTooLowException();
}
