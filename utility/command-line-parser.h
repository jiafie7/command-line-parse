#pragma once

#include <map>
#include "utility/value.h"

namespace melon
{
  namespace utility
  {
    class CommandLineParser
    {
      public:
        enum ArgType
        {
          ARG_UNKNOWN = 0,
          ARG_NO,
          ARG_OPTIONAL,
          ARG_REQUIRED,
        };

        CommandLineParser() = default;
        ~CommandLineParser() = default;

        void add(const std::string& opt, ArgType type);
        ArgType getType(const std::string& opt) const;

        void parse(int argc, char* argv[]);
        void show() const;

        bool has(const std::string& arg) const;
        // bool get_bool(const std::string& arg);
        // int get_int(const std::string& arg);
        // std::string get_string(const std::string& arg);
        Value get(const std::string& arg);



      private:
        std::map<std::string, ArgType> m_types;
        std::map<std::string, std::string> m_args;
    };
  }
}
