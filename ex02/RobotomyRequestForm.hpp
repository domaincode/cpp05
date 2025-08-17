#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>


class RobotomyRequestForm:public AForm{
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& original);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& original);
        void execute(Bureaucrat const & executor) const;
};

#endif