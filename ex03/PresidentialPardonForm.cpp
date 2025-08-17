#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:AForm("Default", 25, 5), target("Default")
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
:AForm("Presidential Pardon", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
:AForm(o), target(o.target)
{

}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& o)
{
    if(this != &o)
    {
        AForm::operator=(o);
        target = o.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{

    if(get_Status() == false)
        throw NotSigned();
    if(get_gradeToExecute() >= executor.getGrade())
    {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
    }
    else
        throw GradeTooLowException();
}