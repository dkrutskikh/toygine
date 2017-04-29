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
  \file   point.hpp
  \brief
*/

#ifndef SRC_MATHEMATICS_POINT_HPP_
#define SRC_MATHEMATICS_POINT_HPP_

#include <cstdint>

namespace toygine {
namespace math {

//! 2D point based on std::int32_t
class point {
 public:
  std::int32_t x;
  std::int32_t y;

  inline point() noexcept;
  inline point(std::int32_t px, std::int32_t py) noexcept;
  explicit inline point(const std::int32_t *intArray) noexcept;

  inline point &operator+=(const point &pnt) noexcept;
  inline point &operator-=(const point &pnt) noexcept;
  inline point &operator*=(int scalar) noexcept;
  inline point &operator*=(float scalar) noexcept;
  inline point &operator/=(std::int32_t scalar) noexcept;

  inline std::int32_t sqrMagnitude() const noexcept;

  inline void setZero() noexcept;

  inline bool isZero() const noexcept;
  //! Checks if this point equals the other one.
  inline bool isEqual(const point &pnt, int eps = 0) const noexcept;
};

inline point operator-(const point &pnt) noexcept;

inline point operator+(const point &left, const point &right) noexcept;
inline point operator-(const point &left, const point &right) noexcept;
inline point operator*(const point &left, int right) noexcept;
inline point operator*(const point &left, float right) noexcept;
inline point operator*(int left, const point &right) noexcept;
inline point operator/(const point &left, int right) noexcept;

inline bool operator==(const point &left, const point &right) noexcept;
inline bool operator!=(const point &left, const point &right) noexcept;

}  // namespace math
}  // namespace toygine

#include "point.inl"

#endif  // SRC_MATHEMATICS_POINT_HPP_
