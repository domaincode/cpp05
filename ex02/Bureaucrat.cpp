#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name("Default"), grade(150)
{
       std::cout << name << ": Bureaucrat Default Constructor Called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name)
{
    if(grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
    std::cout << name << ": Bureaucrat Para Constructor Called\n"; 

}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
:name(other.name), grade(other.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
        this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << name << ": Bureaucrat Destructor Called\n"; 
}

int Bureaucrat::getGrade()const
{
    return grade;
}

const std::string& Bureaucrat::getName()const
{
    return name;
}

void Bureaucrat::increment()
{
    if(grade == 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement()
{
    if(grade == 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm& form)const
{
    try{
        form.beSigned(*this);
    }
    catch(std::exception& e)
    {
        std::cout << name << " couldn’t sign " << form.get_Name() 
        << " because " << "His Grade Was Too Low\n";
        return ;
    }
    std::cout << name << " signed " << form.get_Name() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)const{
    try{
        form.execute(*this);
    }
    catch(std::exception& e)
    {
        std::cout << name << " couldn't execute " << form.get_Name() << std::endl;
        return ;
    }
    std::cout << name << " execute " << form.get_Name() << std::endl;

}

const char* Bureaucrat::GradeTooHighException::what()const throw(){

    return "Bureaucrat: Grade Too High !!!\n";
}

const char* Bureaucrat::GradeTooLowException::what()const throw(){

    return "Bureaucrat: Grade Too Low !!!\n";
}


///////  << overloading /////////////////////////////

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& object)
{
    std::cout << object.getName() << ", bureaucrat grade " << object.getGrade();
    return COUT;
}