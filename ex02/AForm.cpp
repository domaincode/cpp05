#include "AForm.hpp"

/// Constructors ///////////////////////////////////
AForm::AForm()
:name("AForm0"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "AForm Default Constructor Called\n";
}

AForm::~AForm()
{
    std::cout << "AForm Destructor Called\n";
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
:name(name),is_signed(false),grade_to_sign(gradeToSign), grade_to_execute(gradeToExecute)
{
    if(grade_to_sign < 1 || grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    else if(grade_to_sign > 150 || grade_to_execute > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm PARA Constructor Called\n";
}

AForm::AForm(const AForm& original)
:name(original.name), is_signed(original.is_signed), grade_to_sign(original.grade_to_sign), 
grade_to_execute(original.grade_to_execute)
{
    std::cout << "AForm Copy Constructor Called\n";
}

AForm& AForm::operator=(const AForm& original)
{
    if(this != &original)
        is_signed = original.is_signed;
    std::cout << "AForm Assignment Constructor Called\n";
    return *this;
}

/// Getters ////////////////////////////////////////////////////

const std::string& AForm::get_Name()const
{
    return name;
}

bool AForm::get_Status()const
{
    return is_signed;
}

int AForm::get_gradeToSign()const
{
    return grade_to_sign;
}

int AForm::get_gradeToExecute()const
{
    return grade_to_execute;
}

//////  beSigned()  ///////////////////////////////////////////////////

void AForm::beSigned(Bureaucrat& object)
{
    if(object.getGrade() <= grade_to_sign)
        is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

/// Exception  ////////////////////////////////////////////////

const char* AForm::GradeTooHighException::what()const throw(){

    return "AForm: Grade Too High !!!\n";
}

const char* AForm::GradeTooLowException::what()const throw(){

    return "AForm: Grade Too Low !!!\n";
}


/////// << overloading //////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const AForm& object)
{
    os << "---------Form inFormation------------\n";
    os << "Name: " << object.get_Name() << std::endl;
    os << "Signed: " << (object.get_Status() ? "yes\n": "No\n");
    os << "Grade Required To Sign it: " << object.get_gradeToSign() << std::endl;
    os << "Grade Required To Execute it: " << object.get_gradeToExecute();
    return os;
}