# Command Line Parse

This project is an effecient and user-friendly C++ command-line argument parsing tool that supports various parameter types and custom options.

## Features

- **Supports multiple parameter types**: such as strings, integers and booleans.
- **Simple API**: Easy to integrate into any C++ project.
- **Flexible parameter handling**: Supports both required and optional arguments.

## Installation

1. Clone the Repository

```bash
git clone https://github.com/jiafie7/command-line-parse.git
cd command-line-parse
```

2. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Getting Started

1. Example code

```c++
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
```

2. Run the Example

- For long arguments, the optional argument only recognizes `--name=Alice`, and the required argument recognizes the `--name=Alice` or `--name Alice`.
- For short arguments, the optional argument only recognizes `-nAlice`, and the required argument only recognizes the `-n Alice`

```bash
./main --name Alice --age=25 --status=true -a -b test -c123
```

3. Output

```bash
Name = Alice
Age = 25
Status = true
a =
b = test
c = 123
```

## API Reference

1. void add(const std::string& arg, ArgType type)

Description: Adds a command-line argument

- opt: Argument name (e.g., --name)
- desrcription: Argument type, indicates whether the argument is required.

2. void parse(int argc, char\* argv[])

Description: Parses the command-line arguments.

3. bool get_bool(const std::string& arg)

Description: Gets the value of arguments.
