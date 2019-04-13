#include "HelloWorld.h"
#include <iostream>
#include <sstream>

HelloWorld::HelloWorld(const std::string &message)
    : m_Message(message)
{
    // empty
}

void HelloWorld::Print() const
{
    std::cout << m_Message << std::endl;
}

void HelloWorld::Append(const std::string &add)
{
    std::stringstream ss;
    ss << m_Message << add;
    m_Message = ss.str();
}

void HelloWorld::Reverse()
{
    auto itBegin = m_Message.begin();
    auto itEnd = m_Message.end();
    itEnd--;
    while (itBegin < itEnd)
    {
        char temp = *itBegin;
        *itBegin = *itEnd;
        *itEnd = temp;

        itBegin++;
        itEnd--;
    }
}