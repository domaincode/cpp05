#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        Form();
        ~Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form& original);
        Form& operator=(const Form& original);

        const std::string& get_Name()const;
        bool get_Status()const;
        int get_gradeToSign()const;
        int get_gradeToExecute()const;
        void beSigned(Bureaucrat& object);

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


};

#endif