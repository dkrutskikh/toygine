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
/*!
  \file   point.inl
  \brief
*/

#ifndef SRC_MATHEMATICS_POINT_INL_
#define SRC_MATHEMATICS_POINT_INL_

#include <cassert>
#include <cstdlib>

namespace toygine {
namespace math {

inline point::point() noexcept : x(), y() {}

inline point::point(std::int32_t px, std::int32_t py) noexcept : x(px), y(py) {}

inline point::point(const std::int32_t *intArray) noexcept
    : x(intArray[0]), y(intArray[1]) {
  assert(intArray != nullptr);
}

inline point &point::operator+=(const point &pnt) noexcept {
  x += pnt.x;
  y += pnt.y;

  return *this;
}

inline point &point::operator-=(const point &pnt) noexcept {
  x -= pnt.x;
  y -= pnt.y;

  return *this;
}

inline point &point::operator*=(int scalar) noexcept {
  x *= scalar;
  y *= scalar;

  return *this;
}

inline point &point::operator*=(float scalar) noexcept {
  x = static_cast<std::int32_t>(x * scalar);
  y = static_cast<std::int32_t>(y * scalar);

  return *this;
}

inline point &point::operator/=(std::int32_t scalar) noexcept {
  assert(scalar != 0);

  x /= scalar;
  y /= scalar;

  return *this;
}

inline std::int32_t point::sqrMagnitude() const noexcept {
  return x * x + y * y;
}

inline void point::setZero() noexcept { x = y = 0; }

inline bool point::isZero() const noexcept { return (x == 0 && y == 0); }

inline bool point::isEqual(const point &pnt, int eps) const noexcept {
  assert(eps >= 0);
  return (std::abs(x - pnt.x) <= eps) && (std::abs(y - pnt.y) <= eps);
}

inline point operator-(const point &pnt) noexcept {
  return point(-pnt.x, -pnt.y);
}

inline point operator+(const point &left, const point &right) noexcept {
  return point(left.x + right.x, left.y + right.y);
}

inline point operator-(const point &left, const point &right) noexcept {
  return point(left.x - right.x, left.y - right.y);
}

inline point operator*(const point &left, int right) noexcept {
  return point(left.x * right, left.y * right);
}

inline point operator*(const point &left, float right) noexcept {
  return point(static_cast<std::int32_t>(left.x * right),
               static_cast<std::int32_t>(left.y * right));
}

inline point operator*(int left, const point &right) noexcept {
  return (right * left);
}

inline point operator/(const point &left, int right) noexcept {
  assert(right != 0);
  return point(left.x / right, left.y / right);
}

inline bool operator==(const point &left, const point &right) noexcept {
  return (left.x == right.x && left.y == right.y);
}

inline bool operator!=(const point &left, const point &right) noexcept {
  return !(left == right);
}

}  // namespace math
}  // namespace toygine

#endif  // SRC_MATHEMATICS_POINT_INL_
