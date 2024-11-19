#pragma once

#include <iostream>
#include <sstream>
#include <string>

namespace melon
{
  namespace utility
  {
    class Value
    {
      public:
        enum ValueType
        {
          V_NULL = 0,
          V_BOOL,
          V_INT,
          V_FLOAT,
          V_DOUBLE,
          V_STRING
        };

        Value();
        explicit Value(bool value);
        explicit Value(int value);
        explicit Value(unsigned int value);
        explicit Value(float value);
        explicit Value(double value);
        explicit Value(const char* value);
        explicit Value(const std::string& value);
        ~Value() = default;

        void show() const;

        Value& operator=(bool value);
        Value& operator=(int value);
        Value& operator=(unsigned int value);
        Value& operator=(float value);
        Value& operator=(double value);
        Value& operator=(const char* value);
        Value& operator=(const std::string& value);
        Value& operator=(const Value& other);

        operator bool();
        operator bool() const;
        operator int();
        operator int() const;
        operator unsigned int();
        operator unsigned int() const;
        operator float();
        operator float() const;
        operator double();
        operator double() const;
        operator std::string();
        operator std::string() const;

      private:
        ValueType m_type;
        std::string m_value;
    };  
  }
}

