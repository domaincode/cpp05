#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
:AForm("Default", 72, 45), target("Default")
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:AForm("Robotomy Request", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
:AForm(o), target(o.target)
{

}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o)
{
    if(this != &o)
    {
        AForm::operator=(o);
        target = o.target;
    }
    return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if(get_Status() == false)
        throw NotSigned();
    if(get_gradeToExecute() >= executor.getGrade())
    {
            std::srand(time(0));
            if(std::rand() % 2 == 0){
                std::cout << target << " has been robotomized successfully\n";
            }
            else{
                std::cout << "the robotomy failed\n";
            }
    }
    else
        throw GradeTooLowException();
}