#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    ShrubberyCreationForm a;
    ShrubberyCreationForm test("kamal");
    Bureaucrat kamal("kamal", 1);

    std::cout << test << std::endl;

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