#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& object)
{
    std::cout << object.getName() << ", bureaucrat grade " << object.getGrade();
    return COUT;
}

std::ostream& operator<<(std::ostream& os, const AForm& object)
{
    os << "---------AForm inAFormation------------\n";
    os << "Name: " << object.get_Name() << std::endl;
    os << "Signed: " << (object.get_Status() ? "yes\n": "No\n");
    os << "Grade Required To Sign it: " << object.get_gradeToSign() << std::endl;
    os << "Grade Required To Execute it: " << object.get_gradeToExecute();
    return os;
}


int main()
{
    ShrubberyCreationForm a;
    ShrubberyCreationForm test("kamal");
    Bureaucrat kamal("kamal", 1);

    test.beSigned(kamal);

    std::cout << test << std::endl;

    a = test;
    std::cout << a<< std::endl;
  //test0();
    // test1();
    // test2();
    //  test3();
    //    test4();

}