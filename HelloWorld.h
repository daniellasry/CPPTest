#pragma once

#include <string>

class HelloWorld
{
public:
    HelloWorld(const std::string &message);

    void Print() const;
    std::string GetMessage() const { return m_Message; }
    void Append(const std::string &add);
    void Reverse();

private:
    std::string m_Message;
};
