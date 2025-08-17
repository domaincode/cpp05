#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
:AForm("Default", 72, 45)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:AForm(target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
:AForm(o)
{

}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o)
{
    if(this != &o)
        AForm::operator=(o);
    return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if(get_Status() == false)
        throw NotSigned();
    if(get_gradeToExecute() >= executor.getGrade())
    {
            std::srand(time(0));
            if(std::rand() % 2 == 0){
                std::cout << get_Name() << " has been robotomized successfully\n";
            }
            else{
                std::cout << "the robotomy failed\n";
            }
    }
    else
        throw GradeTooLowException();
}