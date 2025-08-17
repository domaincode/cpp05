#include "Form.hpp"

/// Constructors ///////////////////////////////////
Form::Form()
:name("Form0"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "Form Default Constructor Called\n";
}

Form::~Form()
{
    std::cout << "Form Destructor Called\n";
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
:name(name),is_signed(false),grade_to_sign(gradeToSign), grade_to_execute(gradeToExecute)
{
    if(grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    else if(grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form PARA Constructor Called\n";
}

Form::Form(const Form& original)
:name(original.name), is_signed(original.is_signed), grade_to_sign(original.grade_to_sign), 
grade_to_execute(original.grade_to_execute)
{
    std::cout << "Form Copy Constructor Called\n";
}

Form& Form::operator=(const Form& original)
{
    if(this != &original)
        is_signed = original.is_signed;
    std::cout << "Form Assignment Constructor Called\n";
    return *this;
}

/// Getters ////////////////////////////////////////////////////

const std::string& Form::get_Name()const
{
    return name;
}

bool Form::get_Status()const
{
    return is_signed;
}

int Form::get_gradeToSign()const
{
    return grade_to_sign;
}

int Form::get_gradeToExecute()const
{
    return grade_to_execute;
}

//////  beSigned()  ///////////////////////////////////////////////////

void Form::beSigned(Bureaucrat& object)
{
    if(object.getGrade() <= grade_to_sign)
        is_signed = true;
    else
        throw Form::GradeTooLowException();
}

/// Exception  ////////////////////////////////////////////////

const char* Form::GradeTooHighException::what()const throw(){

    return "Form: Grade Too High !!!\n";
}

const char* Form::GradeTooLowException::what()const throw(){

    return "Form: Grade Too Low !!!\n";
}


////// << overloading ////////////////////////

std::ostream& operator<<(std::ostream& os, const Form& object)
{
    os << "---------Form information------------\n";
    os << "Name: " << object.get_Name() << std::endl;
    os << "Signed: " << (object.get_Status() ? "yes\n": "No\n");
    os << "Grade Required To Sign it: " << object.get_gradeToSign() << std::endl;
    os << "Grade Required To Execute it: " << object.get_gradeToExecute();
    return os;
}
