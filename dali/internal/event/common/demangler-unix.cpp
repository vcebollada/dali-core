/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// FILE HEADER
#include <dali/internal/event/common/demangler.h>

// INTERNAL HEADERS
#include <dali/public-api/common/vector-wrapper.h>

namespace
{

// true if character represent a digit
inline bool IsDigit(char c)
{
  return (c >= '0' && c <= '9');
}

// Gets the number of characters (number is in string)
//   start The start position to look for a number
//   result The number as an integer
//   returns the number of characters used to define the number ie '12' is 2
size_t GetNumberOfCharacters(const std::string& s, const size_t& start, int& result)
{
  size_t size = s.size();

  size_t i = start;

  int number = 0;

  for( ; i < size; ++i )
  {
    char c = s.at(i);
    if( !IsDigit( c ) )
    {
      break;
    }
    else
    {
      number = 10 * number + (c - '0');
    }
  }

  if( i - start )
  {
    result = number;
  }

  return i - start;
}

/**
 * @brief Demangle a nested typeid name into its component parts.
 * A nested type name is one containing namespaces and class names only.
 *   eg DemangleNestedNames(typeid(Dali::Actor).name());
 * @param[in] typeIdName The type id name string to demangle.
 * @returns the demangled list of names ie ["Dali","Actor"] or an empty list
 */
std::vector<std::string> DemangleNestedNames(const char *typeIdName)
{
  // Demangle class name mangled according to the Itanium C++ ABI
  // Returns demangled names ie "N4Dali8Internal5ActorE" is ["Dali","Internal","Actor"]
  std::vector<std::string> ret;

  const std::string mangledName(typeIdName);


  size_t size = mangledName.size();

  if( size >= 2 )
  {
    int number = 0;
    size_t start = 0;

    // If the class isnt nested in a namespace then it just starts with the
    // number of characters
    if(mangledName[0] == 'N' && mangledName[size-1]  == 'E')
    {
      start = 1;
    }

    while( size_t chars = GetNumberOfCharacters(mangledName, start, number) )
    {
      ret.push_back( mangledName.substr( start + chars, number ) );

      start += chars + number;
    }
  }

  return ret;
}

} // anon namespace

namespace Dali
{

namespace Internal
{

const std::string DemangleClassName(const char *typeIdName)
{
  std::string name;
  std::vector<std::string> names = DemangleNestedNames(typeIdName);

  if( names.size() )
  {
    name = names[ names.size() - 1 ];
  }

  return name;
}

} // namespace Internal

} // namespace Dali
