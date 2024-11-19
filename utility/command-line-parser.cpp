#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include "utility/command-line-parser.h"

using namespace melon::utility;


CommandLineParser::ArgType CommandLineParser::getType(const std::string& arg) const
{
  auto it = m_types.find(arg);
  return it != m_types.end() ? it->second : ARG_UNKNOWN;
}

void CommandLineParser::add(const std::string& arg, CommandLineParser::ArgType type)
{
  m_types[arg] = type;
}


void CommandLineParser::parse(int argc, char* argv[])
{
  for (int i = 1; i < argc; ++ i)
  {
    std::string arg = argv[i];
    // argument value
    if (arg.substr(0, 1) != "-")
      continue;
    // long argument (e.g. --name)
    else if (arg.substr(0, 2) == "--")
    {
      std::string str = arg.substr(2);
      int pos = str.find("=");
      if (pos == std::string::npos) 
      {
        switch (getType(str))
        {
          case ARG_NO:
          case ARG_OPTIONAL:
            m_args[str] = "";
            break;
          case ARG_REQUIRED:
          {
            if (i + 1 > argc)
              throw std::logic_error("Option required argument " + str);
            std::string value = argv[i + 1];
            if (value.substr(0, 1) == "-")
              throw std::logic_error("Option missing argument " + str);
            m_args[str] = value;
            ++ i;
            break;
          }
          default: break;
        }
      }
      else
      {
        std::string key = str.substr(0, pos);
        std::string value = str.substr(pos + 1);
        switch (getType(key))
        {
          case ARG_NO:
            throw std::logic_error("No argument: " + str);
          case ARG_OPTIONAL:
          case ARG_REQUIRED:
          {
            m_args[key] = value;
            break;
          }
          default: break;
        }
      }
    }
    // short (e.g. -n)
    else 
    {
      std::string str = arg.substr(1, 1);
      switch (getType(str))
      {
        case ARG_NO:
        {
          if (arg.length() > 1)
          {
            for (int j = 1; j < arg.length(); ++ j)
            {
              std::string key(1, arg[j]);
              if (getType(key) != ARG_NO) continue;
              m_args[key] = "";
            }
          }
          break;
        }
        case ARG_OPTIONAL:
        {
          if (arg.length() > 2)
            m_args[str] = arg.substr(2);
          else
            m_args[str] = "";
          break;
        }
        case ARG_REQUIRED:
        {
          if (i + 1 > argc)
            throw std::logic_error("Option required argument " + str);
          std::string value = argv[i + 1];
          if (value.substr(0, 1) == "-")
            throw std::logic_error("Option missing argument " + str);
          m_args[str] = value;
          ++ i;
          break;
        }
        default: break;
      }
    }
  }
}

void CommandLineParser::show() const
{
  for (const std::pair<std::string, std::string> arg : m_args)
    std::cout << arg.first << ": " << arg.second << '\n';
}


bool CommandLineParser::has(const std::string& arg) const
{
  return m_types.find(arg) != m_types.end()
      && m_args.find(arg) != m_args.end();
}
        
// bool CommandLineParser::get_bool(const std::string& arg)
// {
//   if (!has(arg))
//     throw std::logic_error("Argument is not exist");
//
//   return m_args[arg] == "true" ? true : false;
// }
//         
// int CommandLineParser::get_int(const std::string& arg)
// {
//   if (!has(arg))
//     throw std::logic_error("Argument is not exist");
//
//   std::stringstream ss;
//   ss << m_args[arg];
//
//   int value = 0;
//   ss >> value;
//   return value;
// }
//         
// std::string CommandLineParser::get_string(const std::string& arg)
// {
//   if (!has(arg))
//     throw std::logic_error("Argument is not exist");
//
//   return m_args[arg];
// }

Value CommandLineParser::get(const std::string& arg)
{
  if (!has(arg))
    return Value("");

  switch (m_types[arg])
  {
    case ARG_NO:
    case ARG_OPTIONAL:
    case ARG_REQUIRED:
      return Value(m_args[arg]);
    default: break;
  }

  return Value("");
}
