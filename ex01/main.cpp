#include "Bureaucrat.hpp"
#include "Form.hpp"





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
  std::cout << "\033[32mTest0\033[0m\n";
    test0();
  std::cout << "\n\033[32mTest1\033[0m\n";
     test1();
  std::cout << "\n\033[32mTest2\033[0m\n";
     test2();
  std::cout << "\n\033[32mTest3\033[0m\n";
      test3();
  std::cout << "\n\033[32mTest4\033[0m\n";
      test4();

}