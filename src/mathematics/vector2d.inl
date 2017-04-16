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
  \file   vector2d.inl
  \brief
*/

#ifndef SRC_MATHEMATICS_VECTOR2D_INL_
#define SRC_MATHEMATICS_VECTOR2D_INL_

#include <cassert>
#include <cmath>
#include <cstdlib>

namespace toygine {
namespace math {

inline vector2d::vector2d()
#ifdef _DEBUG
    : x(std::nanf("")),
      y(std::nanf(""))
#else
    : x(),
      y()
#endif
{
}

inline vector2d::vector2d(float _x, float _y) : x(_x), y(_y) {}

inline vector2d::vector2d(std::int32_t _x, std::int32_t _y)
    : x(static_cast<float>(_x)), y(static_cast<float>(_y)) {}

inline vector2d::vector2d(const point &pnt)
    : x(static_cast<float>(pnt.x)), y(static_cast<float>(pnt.y)) {}

inline vector2d::vector2d(const float *floatArray)
    : x(floatArray[0]), y(floatArray[1]) {
  assert(floatArray != nullptr);
}

inline point vector2d::toPoint() const {
  return point(static_cast<std::int32_t>(x), static_cast<std::int32_t>(y));
}

inline vector2d &vector2d::operator+=(const vector2d &v) {
  x += v.x;
  y += v.y;

  return *this;
}

inline vector2d &vector2d::operator-=(const vector2d &v) {
  x -= v.x;
  y -= v.y;

  return *this;
}

inline vector2d &vector2d::operator*=(float scalar) {
  x *= scalar;
  y *= scalar;

  return *this;
}

inline vector2d &vector2d::operator/=(float scalar) {
  assert(std::abs(scalar) > std::numeric_limits<float>::epsilon());

  *this *= (1.0f / scalar);
  return *this;
}

inline float vector2d::magnitude() const { return std::sqrt(sqrMagnitude()); }

inline float vector2d::sqrMagnitude() const { return x * x + y * y; }

inline void vector2d::normalize() {
  const float len = magnitude();
  if (len > std::numeric_limits<float>::epsilon()) {
    *this /= len;
  } else {
    setZero();
    y = 1.0f;
  }
}

inline void vector2d::setZero() { x = y = 0.0f; }

inline bool vector2d::isZero() const {
  return (std::abs(x) <= std::numeric_limits<float>::epsilon()) &&
         (std::abs(y) <= std::numeric_limits<float>::epsilon());
}

inline bool vector2d::isEqual(const vector2d &v, float eps) const {
  assert(eps >= 0.0f);

  return (std::abs(x - v.x) <= eps) && (std::abs(y - v.y) <= eps);
}

inline vector2d operator-(const vector2d &vec) {
  return vector2d(-vec.x, -vec.y);
}

inline vector2d operator+(const vector2d &left, const vector2d &right) {
  return vector2d(left.x + right.x, left.y + right.y);
}

inline vector2d operator-(const vector2d &left, const vector2d &right) {
  return vector2d(left.x - right.x, left.y - right.y);
}

inline vector2d operator*(const vector2d &left, float right) {
  return vector2d(left.x * right, left.y * right);
}

inline vector2d operator*(float left, const vector2d &right) {
  return (right * left);
}

inline vector2d operator/(const vector2d &left, float right) {
  assert(std::abs(right) > std::numeric_limits<float>::epsilon());

  return (left * (1.0f / right));
}

inline bool operator==(const vector2d &left, const vector2d &right) {
  return left.isEqual(right);
}

inline bool operator!=(const vector2d &left, const vector2d &right) {
  return !(left == right);
}

inline float operator*(const vector2d &left, const vector2d &right) {
  return (left.x * right.x + left.y * right.y);
}

inline float cross(const vector2d &left, const vector2d &right) {
  return (left.x * right.y - left.y * right.x);
}

}  // namespace math
}  // namespace toygine

#endif  // SRC_MATHEMATICS_VECTOR2D_INL_
