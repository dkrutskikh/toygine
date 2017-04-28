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
  \file   vector2d.hpp
  \brief
*/

#ifndef SRC_MATHEMATICS_VECTOR2D_HPP_
#define SRC_MATHEMATICS_VECTOR2D_HPP_

#include <limits>
#include "point.hpp"

namespace toygine {
namespace math {

//! 2D vector
class vector2d {
 public:
  float x;
  float y;

  inline vector2d();
  inline vector2d(float x, float y);
  inline vector2d(std::int32_t x, std::int32_t y);
  explicit inline vector2d(const point &pnt);
  explicit inline vector2d(const float *floatArray);

  inline point toPoint() const;

  inline vector2d &operator+=(const vector2d &vec);
  inline vector2d &operator-=(const vector2d &vec);
  inline vector2d &operator*=(float scalar);
  inline vector2d &operator/=(float scalar);

  inline float magnitude() const;
  inline float sqrMagnitude() const;

  inline void normalize();

  inline void setZero();

  void rotate(float angle);

  inline bool isZero() const;
  //! Checks if this vector equals the other one.
  inline bool isEqual(const vector2d &v,
                      float eps = std::numeric_limits<float>::epsilon()) const;
};

inline vector2d operator-(const vector2d &vec);

inline vector2d operator+(const vector2d &left, const vector2d &right);
inline vector2d operator-(const vector2d &left, const vector2d &right);
inline vector2d operator*(const vector2d &left, float right);
inline vector2d operator*(float left, const vector2d &right);
inline vector2d operator/(const vector2d &left, float right);

inline bool operator==(const vector2d &left, const vector2d &right);
inline bool operator!=(const vector2d &left, const vector2d &right);

inline float operator*(const vector2d &left, const vector2d &right);
inline float cross(const vector2d &left, const vector2d &right);

}  // namespace math
}  // namespace toygine

#include "vector2d.inl"

#endif  // SRC_MATHEMATICS_VECTOR2D_HPP_
