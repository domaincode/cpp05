#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:AForm("Default", 25, 5)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
:AForm(target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
:AForm(o)
{

}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& o)
{
    if(this != &o)
        AForm::operator=(o);
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{

    if(get_Status() == false)
        throw NotSigned();
    if(get_gradeToExecute() >= executor.getGrade())
    {
        std::cout << get_Name() << " has been pardoned by Zaphod Beeblebrox\n";
    }
    else
        throw GradeTooLowException();
}