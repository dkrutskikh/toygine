//
// Copyright (c) 2017 Dmitry Krutskikh
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
/*
\file   logger.hpp
\brief  APIs for debugging and error logging
*/

#ifndef SRC_CORE_LOGGER_HPP_
#define SRC_CORE_LOGGER_HPP_

#include <string>

namespace toygine {
namespace log {

class level {
 public:
  inline level(std::string &&name, int value) noexcept;
  inline level(const std::string &name, int value) noexcept;
  inline level(level &&instance) noexcept;
  inline level(const level &instance) noexcept;

  static const level ALL;
  static const level FINEST;
  static const level FINER;
  static const level FINE;
  static const level CONFIG;
  static const level INFO;
  static const level WARNING;
  static const level SEVERE;
  static const level SHOUT;
  static const level OFF;

  inline level &operator=(level &&instance) noexcept;
  inline level &operator=(const level &instance) noexcept;

  inline bool operator==(const level &other) const noexcept;
  inline bool operator<(const level &other) const noexcept;

 private:
  std::string _name;
  int _value;
};

inline bool operator!=(const level &left, const level &right) noexcept;
inline bool operator>(const level &left, const level &right) noexcept;
inline bool operator<=(const level &left, const level &right) noexcept;
inline bool operator>=(const level &left, const level &right) noexcept;

}  // namespace log
}  // namespace toygine

#include "logger.inl"

#endif  // SRC_CORE_LOGGER_HPP_
