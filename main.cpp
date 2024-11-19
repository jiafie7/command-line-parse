#include <iostream>
#include "utility/command-line-parser.h"
#include "utility/value.h"

using namespace melon::utility;

int main(int argc, char* argv[])
{
    CommandLineParser parser;

    parser.add("name", CommandLineParser::ARG_REQUIRED);
    parser.add("age", CommandLineParser::ARG_OPTIONAL);
    parser.add("status", CommandLineParser::ARG_OPTIONAL);
    parser.add("a", CommandLineParser::ARG_NO);
    parser.add("b", CommandLineParser::ARG_REQUIRED);
    parser.add("c", CommandLineParser::ARG_OPTIONAL);

    parser.parse(argc, argv);                  

    std::string name = parser.get("name");
    std::cout << "Name = " << name << '\n';

    int age = parser.get("age");
    std::cout << "Age = " << age << '\n';

    bool status = parser.get("status");
    std::cout << std::boolalpha;
    std::cout << "Status = " << status << '\n';
    std::cout << std::noboolalpha;

    std::string a = parser.get("a");
    std::cout << "a = " << a << '\n';

    std::string b = parser.get("b");
    std::cout << "b = " << b << '\n';

    int c = parser.get("c");
    std::cout << "c = " << c << '\n';

    return 0;
}


