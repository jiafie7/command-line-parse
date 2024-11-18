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
```

2. Run the Example

- For long arguments, the optional argument only recognizes `--name=Alice`, and the required argument recognizes the `--name=Alice` or `--name Alice`.
- For short arguments, the optional argument only recognizes `-nAlice`, and the required argument only recognizes the `-n Alice`

```bash
./main --name Alice --age=25 --status=true
```

3. Output

```bash
Name: Alice
Age: 25
Status: true
```

## API Reference

1. void add(const std::string& opt, Type type)

Description: Adds a command-line argument

- opt: Argument name (e.g., --name)
- desrcription: Argument type, indicates whether the argument is required.

2. void parse(int argc, char\* argv[])

Description: Parses the command-line arguments.

3. bool has(const std::string& opt) const

Description: Indicates whether the argument is existed.

4. bool get_bool(const std::string& opt)

Description: Gets the value of boolean parameter type.

5. int get_int(const std::string& opt)

Description: Gets the value of integer parameter type.

6. std::string get_string(const std::string& opt)

Description: Gets the value of string parameter type.
