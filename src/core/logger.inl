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

#ifndef SRC_CORE_LOGGER_INL_
#define SRC_CORE_LOGGER_INL_

namespace toygine {
namespace log {

inline level::level(const std::string &name, int value) noexcept
    : _name(name), _value(value) {}

inline level::level(std::string &&name, int value) noexcept
    : _name(name), _value(value) {}

inline level::level(level &&instance) noexcept
    : _name(instance._name), _value(instance._value) {}

inline level::level(const level &instance) noexcept
    : _name(instance._name), _value(instance._value) {}

inline level &level::operator=(level &&instance) noexcept {
  std::swap(_name, instance._name);
  _value = instance._value;
  return *this;
}

inline level &level::operator=(const level &instance) noexcept {
  _name = instance._name;
  _value = instance._value;
  return *this;
}

inline bool level::operator==(const level &other) const noexcept {
  return _value == other._value;
}

inline bool level::operator<(const level &other) const noexcept {
  return _value < other._value;
}

inline bool operator!=(const level &left, const level &right) noexcept {
  return !(left == right);
}
inline bool operator>(const level &left, const level &right) noexcept {
  return right < left;
}
inline bool operator<=(const level &left, const level &right) noexcept {
  return !(left > right);
}
inline bool operator>=(const level &left, const level &right) noexcept {
  return !(left < right);
}

}  // namespace log
}  // namespace toygine

#endif  // SRC_CORE_LOGGER_INL_
