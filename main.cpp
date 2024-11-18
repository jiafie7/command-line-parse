#include <iostream>
#include "utility/command-line-parser.h"

using namespace melon::utility;

int main(int argc, char* argv[])
{
    CommandLineParser parser;
    
    parser.add("name", CommandLineParser::ARG_REQUIRED);
    parser.add("age", CommandLineParser::ARG_OPTIONAL);
    parser.add("status", CommandLineParser::ARG_OPTIONAL);
    
    parser.parse(argc, argv);                  

    std::cout << std::boolalpha;
    bool name = parser.get_bool("name");
    std::cout << "Name = " << name << '\n';
    std::cout << std::noboolalpha;

    int age = parser.get_int("age");
    std::cout << "Age = " << age << '\n';
    
    std::string status = parser.get_string("status");
    std::cout << "Status = " << status << '\n';

    return 0;
}


