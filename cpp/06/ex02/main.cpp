#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int num = std::rand() % 3;

    switch(num){
        case 0:
            std::cout << "generate :: Base A" << std::endl;
            return new A;
        case 1:
            std::cout << "generate :: Base B" << std::endl;
            return new B;
        case 2:
            std::cout << "generate :: Base C" << std::endl;
            return new C;
    }
    return NULL;
}


void identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "identify pointer :: A class" << std::endl;
	else if (b)
		std::cout << "identify pointer :: B class" << std::endl;
	else if (c)
		std::cout << "identify pointer :: C class" << std::endl;
	else
		std::cout << "identify pointer :: Base class" << std::endl;
}

void identify(Base& p)
{
    try{
        A& a = dynamic_cast<A&> (p);
        static_cast<void>(a);
        std::cout << "identify reference :: A class" << std::endl;
        return;
    }
    catch( const std :: bad_cast &e ) {}
    try{
        B& b = dynamic_cast<B&>(p);
        static_cast<void>(b);
        std::cout << "identify reference :: B class" << std::endl;
        return;
    }
    catch( const std :: bad_cast &e ) {}
    try{
        C& c =  dynamic_cast<C&>(p);
        static_cast<void>(c);
        std::cout << "identify reference :: C class" << std::endl;
        return;
    }
    catch( const std :: bad_cast &e ) {}
    std::cout << "identify reference :: Base class" << std::endl;
}

int main(void)
{
    std::srand(std::time(NULL));

    Base* base = new Base();
	identify(base);
	identify(*base);

    delete base;

    std::cout << "-------------------------------------------" << std::endl;
	
    Base* new_base;
	new_base = generate();
	identify(new_base);
	identify(*new_base);

    delete new_base;

    return 0;
}