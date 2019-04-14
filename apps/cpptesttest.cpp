#include <iostream>
#include "HelloWorld.hpp"

int main()
{
    HelloWorld greeter("Hello World!");
    greeter.Print();
    greeter.Append(" Have a good one!");
    greeter.Print();
    std::cout << "The message: " << greeter.GetMessage() << std::endl;
    greeter.Reverse();
    greeter.Print();
}