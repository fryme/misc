#include "shared_ptr.h"
#include <iostream>

struct SomeClass
{
	SomeClass(int i)
	{
		someValue = i;
		std::cout << "SomeClass created " << i << std::endl;
	}

	~SomeClass()
	{
		std::cout << "SomeClass destroyed" << std::endl;
	}

	void foo() { std::cout << "foo call" << std::endl; }

	int someValue;
};


void Test2(shared_ptr<SomeClass> ptr)
{

}

void Test()
{
	shared_ptr<SomeClass> ptr(new SomeClass(10)); //= new shared_ptr<SomeClass>(10);
	//Test2(ptr);
	//ptr->foo();
	//shared_ptr<SomeClass> otherPtr(ptr);
}

#include <memory>

void StdTest2(std::shared_ptr<SomeClass> ptr)
{

}

void StdTest()
{
	std::shared_ptr<SomeClass> ptr(new SomeClass(10));
	StdTest2(ptr);
}

int main()
{
	//Test();
	StdTest();
	return 0;
}