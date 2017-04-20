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
#include "../../../src/mathematics/vector2d.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../../ext/catch/single_include/catch.hpp"
using toygine::math::point;
using toygine::math::vector2d;

TEST_CASE("Vector2d tests", "[Vector2dTests]") {
  const vector2d testVector1(11.5f, -12.5f);
  const vector2d testVector2(-12, 22);

  SECTION("toPoint") {
    vector2d v1 = testVector1;
    vector2d v2 = -v1;

    const point testPoint1 = v1.toPoint();
    const point testPoint2 = v2.toPoint();

    REQUIRE(testPoint1 == -testPoint2);

    vector2d v3(testPoint1);
    vector2d v4(testPoint2);

    const point testPoint3 = v3.toPoint();
    const point testPoint4 = v4.toPoint();

    REQUIRE(testPoint3 == -testPoint4);
  }
  SECTION("addAssign") {
    vector2d v1, v2;

    v1 = testVector1;
    REQUIRE((v1 + testVector2).x == Approx(-0.5f));
    REQUIRE((v1 + testVector2).y == Approx(9.5f));

    v2 = testVector2;
    REQUIRE((v2 + testVector1).x == Approx(-0.5f));
    REQUIRE((v2 + testVector1).y == Approx(9.5f));

    v1 += testVector2;
    v2 += testVector1;

    REQUIRE(v1.x == Approx(-0.5f));
    REQUIRE(v1.y == Approx(9.5f));
    REQUIRE(v2.x == Approx(-0.5f));
    REQUIRE(v2.y == Approx(9.5f));
  }
  SECTION("subAssign") {
    vector2d v1 = testVector1;
    vector2d v2 = testVector2;

    REQUIRE((v1 - testVector2).x == Approx(23.5f));
    REQUIRE((v1 - testVector2).y == Approx(-34.5f));
    REQUIRE((v2 - testVector1).x == Approx(-23.5f));
    REQUIRE((v2 - testVector1).y == Approx(34.5f));

    v1 -= testVector2;
    v2 -= testVector1;

    REQUIRE(v1.x == Approx(23.5f));
    REQUIRE(v1.y == Approx(-34.5f));
    REQUIRE(v2.x == Approx(-23.5f));
    REQUIRE(v2.y == Approx(34.5f));
  }
  SECTION("mulAssign") {
    vector2d v1 = testVector1;
    vector2d v2 = testVector2;

    REQUIRE((v1 * 5).x == Approx(57.5f));
    REQUIRE((v1 * 5).y == Approx(-62.5f));
    REQUIRE((v2 * -2).x == Approx(24.0f));
    REQUIRE((v2 * -2).y == Approx(-44.0f));

    REQUIRE((5 * v1).x == Approx(57.5f));
    REQUIRE((5 * v1).y == Approx(-62.5f));
    REQUIRE((-2 * v2).x == Approx(24.0f));
    REQUIRE((-2 * v2).y == Approx(-44.0f));

    v1 *= 5.0f;
    v2 *= -2.0f;

    REQUIRE(v1.x == Approx(57.5f));
    REQUIRE(v1.y == Approx(-62.5f));
    REQUIRE(v2.x == Approx(24.0f));
    REQUIRE(v2.y == Approx(-44.0f));

    REQUIRE((v1 * -2.15f).x == Approx(-123.625f));
    REQUIRE((v1 * -2.15f).y == Approx(134.375f));
    REQUIRE((v2 * 0.25f).x == Approx(6.0f));
    REQUIRE((v2 * 0.25f).y == Approx(-11.0f));

    v1 *= -2.15f;
    v2 *= 0.25f;

    REQUIRE(v1.x == Approx(-123.625f));
    REQUIRE(v1.y == Approx(134.375f));
    REQUIRE(v2.x == Approx(6.0f));
    REQUIRE(v2.y == Approx(-11.0f));
  }
  SECTION("divAssign") {
    vector2d v1 = testVector1;
    vector2d v2 = testVector2;

    REQUIRE((v1 / 2).x == Approx(5.75f));
    REQUIRE((v1 / 2).y == Approx(-6.25f));
    REQUIRE((v2 / -2).x == Approx(6.0f));
    REQUIRE((v2 / -2).y == Approx(-11.0f));

    v1 /= 2.0f;
    v2 /= -2.0f;

    REQUIRE(v1.x == Approx(5.75f));
    REQUIRE(v1.y == Approx(-6.25f));
    REQUIRE(v2.x == Approx(6.0f));
    REQUIRE(v2.y == Approx(-11.0f));
  }
  SECTION("magnitude") {
    REQUIRE(testVector1.magnitude() == Approx(16.9853f));
    REQUIRE(testVector2.magnitude() == Approx(25.06f));

    REQUIRE(testVector1.sqrMagnitude() == Approx(288.5f));
    REQUIRE(testVector2.sqrMagnitude() == Approx(628.0f));
  }
  SECTION("normalize") {
    vector2d testVector = vector2d(0, 0);
    testVector.normalize();
    REQUIRE(testVector.x == Approx(0.0f));
    REQUIRE(testVector.y == Approx(1.0f));

    REQUIRE(testVector.magnitude() == Approx(1.0f));

    vector2d v1 = testVector1;
    vector2d v2 = testVector2;

    v1.normalize();
    v2.normalize();

    REQUIRE(v1.x == Approx(0.67706f));
    REQUIRE(v1.y == Approx(-0.73593f));

    REQUIRE(v2.x == Approx(-0.47885f));
    REQUIRE(v2.y == Approx(0.8779f));
  }
  SECTION("setZero") {
    vector2d v1 = testVector1;
    vector2d v2 = testVector2;

    REQUIRE_FALSE(v1.x == Approx(0.0f));
    REQUIRE_FALSE(v1.y == Approx(0.0f));
    REQUIRE_FALSE(v2.x == Approx(0.0f));
    REQUIRE_FALSE(v2.y == Approx(0.0f));

    v1.setZero();
    v2.setZero();

    REQUIRE(v1.x == Approx(0.0f));
    REQUIRE(v1.y == Approx(0.0f));
    REQUIRE(v2.x == Approx(0.0f));
    REQUIRE(v2.y == Approx(0.0f));
  }
  SECTION("rotate") {
    const vector2d v1(1.0f, 0.0f);
    vector2d v2 = v1;

    const float angleStep = 0.1f;
    for (float angle = angleStep; angle < 2.0f * M_PI; angle += angleStep) {
      v2.rotate(angleStep);

      vector2d v3 = v1;
      v3.rotate(angle);

      REQUIRE(v2.x == Approx(v3.x));
      REQUIRE(v2.y == Approx(v3.y));
    }
  }
  SECTION("isZero") {
    static const float arr[] = {0.0f, 0.0f};
    vector2d v1 = testVector1;
    vector2d v2(arr);

    REQUIRE(!v1.isZero());
    REQUIRE(v2.isZero());

    v1.x = v1.y = 0.0f;

    REQUIRE(v1.isZero());
  }
  SECTION("isEqual") {
    vector2d v1 = testVector1;
    vector2d v2 = testVector1;

    REQUIRE(v1.isEqual(v2));

    v2.x += 3.0f;

    REQUIRE_FALSE(v1.isEqual(v2));
    REQUIRE(v1.isEqual(v2, 3.0f));
  }
  SECTION("minus") {
    vector2d v1 = -testVector1;

    REQUIRE_FALSE(v1.x == Approx(testVector1.x));
    REQUIRE_FALSE(v1.y == Approx(testVector1.y));

    REQUIRE(-v1.x == Approx(testVector1.x));
    REQUIRE(-v1.y == Approx(testVector1.y));
  }
  SECTION("equaling") {
    vector2d v1 = testVector1;
    vector2d v2 = testVector2;

    REQUIRE(v1 == testVector1);
    REQUIRE(v2 == testVector2);

    REQUIRE_FALSE(testVector1 == testVector2);
    REQUIRE_FALSE(v1 == v2);
  }
  SECTION("multiplication") {
    // Scalar multiply
    {
      vector2d v1 = vector2d(0.0f, 1.0f);
      vector2d v2 = vector2d(1.0f, 0.0f);
      REQUIRE(v1 * v2 == Approx(0.0f));

      v2 = vector2d(-1.0f, 0.0f);
      REQUIRE(v1 * v2 == Approx(0.0f));

      v2 = vector2d(0.0f, 1.0f);
      REQUIRE(v1 * v2 == Approx(1.0f));

      v2 = vector2d(0.0f, -1.0f);
      REQUIRE(v1 * v2 == Approx(-1.0f));
    }

    // Vector multiply
    {
      vector2d v1 = vector2d(0.0f, 1.0f);
      vector2d v2 = vector2d(1.0f, 0.0f);
      REQUIRE(toygine::math::cross(v1, v2) == Approx(-1.0f));

      v2 = vector2d(-1.0f, 0.0f);
      REQUIRE(toygine::math::cross(v1, v2) == Approx(1.0f));

      v2 = vector2d(0.0f, 1.0f);
      REQUIRE(toygine::math::cross(v1, v2) == Approx(0.0f));

      v2 = vector2d(0.0f, -1.0f);
      REQUIRE(toygine::math::cross(v1, v2) == Approx(0.0f));
    }
  }
}
