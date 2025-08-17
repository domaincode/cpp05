#include "Bureaucrat.hpp"

void test0()
{
    Bureaucrat kid("John", 1);
    std::cout << kid << std::endl;
}

void test1()
{
    try{
        Bureaucrat kid("kid", 151);
    }
    catch(std::exception& e){
        std::cout << "Catchaa: " << e.what();
    }
}

void test2()
{
    try{
        Bureaucrat kid("kid", 0);
    }
    catch(std::exception& e){
        std::cout << "Catchaa: " << e.what();
    }
}

void test3()
{
    try{
            Bureaucrat a("john", 1);
            std::cout << a << std::endl;
            try{
                a.increment();
                std::cout << a << std::endl;
            }
            catch(std::exception& e)
            {
                std::cout << "Catch0: " << e.what();
             //   throw;
            }
    }
    catch(std::exception& e){
                std::cout << "Catch1: " << e.what();
            }
}

void test4()
{

    try{
        Bureaucrat a("john", 12);
        std::cout << a << std::endl;
        a.decrement();
        std::cout << a << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Catchaa: " << e.what();
    }

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