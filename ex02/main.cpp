#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test0()
{
  try{
        ShrubberyCreationForm contract("contract");
        Bureaucrat john("john", 3);
        contract.beSigned(john);
        contract.execute(john);
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
      RobotomyRequestForm contract("contract");
      Bureaucrat john("john", 2);
      contract.beSigned(john);
      contract.execute(john);
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
    try{
      PresidentialPardonForm contract("contract");
      Bureaucrat john("john", 2);
      //contract.beSigned(john);
      contract.execute(john);
  }
  catch(std::exception& e)
  {
    std::cout << "catcha: " << e.what();
    return ;
  }
  std::cout << "No exception\n";
}

void test3()
{
  Bureaucrat john("john", 4);
  Bureaucrat manager("manager", 2);
  ShrubberyCreationForm contract("contract");
  manager.signForm(contract);

  john.executeForm(contract);
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
}