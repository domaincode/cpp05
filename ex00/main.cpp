#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& COUT, const Bureaucrat& object)
{
    std::cout << object.getName() << ", bureaucrat grade " << object.getGrade();
    return COUT;
}

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
   test0();
//    test1();
//    test2();
//     test3();
//    test4();
}