#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& object)
{
    std::cout << object.getName() << ", bureaucrat grade " << object.getGrade();
    return COUT;
}

std::ostream& operator<<(std::ostream& os, const Form& object)
{
    os << "---------Form information------------\n";
    os << "Name: " << object.get_Name() << std::endl;
    os << "Signed: " << (object.get_Status() ? "yes\n": "No\n");
    os << "Grade Required To Sign it: " << object.get_gradeToSign() << std::endl;
    os << "Grade Required To Execute it: " << object.get_gradeToExecute();
    return os;
}

void test0()
{
    try{
            Form form("Contract", 0, 1);
    }
    catch(std::exception& e)
    {
        std::cout << "catcha: " << e.what();
        return ;
    }
    std::cout << "No exception\n";
}

void test1()
{
    try{
            Form form("Contract", 151, 1);
    }
    catch(std::exception& e)
    {
        std::cout << "catcha: " << e.what();
        return ;
    }
    std::cout << "No exception\n";
}

void test2()
{
   // Form form;
   Form form("The Contract", 1, 1);
   std::cout << form << std::endl;
}

void test3()
{
    try{
        Bureaucrat Manager("John", 3);
        Form form("The Contract", 4, 12);
        std::cout << form << std::endl;
        
        form.beSigned(Manager);

        std::cout << form << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Catchaa: " << e.what();
        return;
    }
    std::cout << "No exception\n";
}


void test4()
{
    try{
        Bureaucrat Manager("john", 2);
        Form form("The Contract", 1, 1);
        Manager.signForm(form);
    }
    catch(std::exception& e)
    {
        std::cout << "Catchaa: " << e.what();
        return;
    }
    std::cout << "No exception\n";

}


int main()
{
  test0();
    // test1();
    // test2();
    //  test3();
    //    test4();

}