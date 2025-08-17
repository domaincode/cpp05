#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        AForm();
        ~AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& original);
        AForm& operator=(const AForm& original);

        const std::string& get_Name()const;
        bool get_Status()const;
        int get_gradeToSign()const;
        int get_gradeToExecute()const;
        void beSigned(const Bureaucrat& object);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        class OpenFailed:public std::exception{
            public:
                const char* what() const throw();
        };

        class NotSigned: public std::exception{
            public:
                const char* what() const throw();
        };


};

std::ostream& operator<<(std::ostream& os, const AForm& object);

#endif