#include "utility/value.h"

using namespace melon::utility;

Value::Value()
  : m_type(V_NULL)
{
}
        
Value::Value(bool value)
  : m_type(V_BOOL)
{
  *this = value;
}

Value::Value(int value)
  : m_type(V_INT)
{
  *this = value;
}

Value::Value(unsigned int value)
  : m_type(V_INT)
{
  *this = value;
}

Value::Value(float value)
  : m_type(V_FLOAT)
{
  *this = value;
}

Value::Value(double value)
  : m_type(V_DOUBLE)
{
  *this = value;
}

Value::Value(const char* value)
  : m_type(V_STRING)
{
  *this = value;
}

Value::Value(const std::string& value)
  : m_type(V_STRING)
{
  *this = value;
}

void Value::show() const
{
  std::string type;
  switch (m_type)
  {
    case V_NULL:
      type = "null";
      break;
    case V_BOOL:
      type = "bool";
      break;
    case V_INT:
      type = "int";
      break;
    case V_FLOAT:
      type = "float";
      break;
    case V_DOUBLE:
      type = "double";
      break;
    case V_STRING:
      type = "string";
      break;
    default:
      break;
  }

  std::cout << "type is " << type << ", value = " << m_value << '\n';
}

Value& Value::operator=(bool value)
{
  m_type = V_BOOL;
  m_value = value ? "true" : "false";
  return *this;
}
       
Value& Value::operator=(int value)
{
  m_type = V_INT;
  m_value = std::to_string(value);
  return *this;
}

Value& Value::operator=(unsigned int value)
{
  m_type = V_INT;
  m_value = std::to_string(value);
  return *this;
}

Value& Value::operator=(float value)
{
  m_type = V_FLOAT;
  m_value = std::to_string(value);
  return *this;
}

Value& Value::operator=(double value)
{
  m_type = V_DOUBLE;
  m_value = std::to_string(value);
  return *this;
}

Value& Value::operator=(const char* value)
{
  m_type = V_STRING;
  m_value = value;
  return *this;
}

Value& Value::operator=(const std::string& value)
{
  m_type = V_STRING;
  m_value = value;
  return *this;
}

Value& Value::operator=(const Value& other)
{
  m_type = other.m_type;
  m_value = other.m_value;
  return *this;
}

Value::operator bool()
{
  return m_value == "true"; 
}

Value::operator bool() const
{
  return m_value == "true"; 
}

Value::operator int()
{
  int value = 0;
  std::stringstream ss;
  ss << m_value;
  ss >> value;
  return value;
}

Value::operator int() const
{
  int value = 0;
  std::stringstream ss;
  ss << m_value;
  ss >> value;
  return value;
}

Value::operator unsigned int()
{
  int value = 0;
  std::stringstream ss;
  ss << m_value;
  ss >> value;
  return value;
}

Value::operator unsigned int() const
{
  int value = 0;
  std::stringstream ss;
  ss << m_value;
  ss >> value;
  return value;
}

Value::operator float()
{
  float value = 0;
  std::stringstream ss;
  ss << m_value;
  ss >> value;
  return value;
}

Value::operator float() const
{
  float value = 0;
  std::stringstream ss;
  ss << m_value;
  ss >> value;
  return value;
}

Value::operator double()
{
  double value = 0;
  std::stringstream ss;
  ss << m_value;
  ss >> value;
  return value;
}

Value::operator double() const
{
  double value = 0;
  std::stringstream ss;
  ss << m_value;
  ss >> value;
  return value;
}

Value::operator std::string()
{
  return m_value;
}

Value::operator std::string() const
{
  return m_value;
}



