#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        std::cout << "--------------------------------------------" << std::endl;
        Bureaucrat chaoh("chaoh",20);
        Form form1("form1",30,50);

        std::cout<< chaoh << std::endl;
        std::cout<< form1 << std::endl;
        chaoh.signForm(form1);
    }
    {
        std::cout << "--------------------------------------------" << std::endl;
        Bureaucrat test("wonyocho",40);
        Form form2("form2",30,50);

        std::cout<< test << std::endl;
        std::cout<< form2 << std::endl;
        test.signForm(form2);
    }

    return 0;
}