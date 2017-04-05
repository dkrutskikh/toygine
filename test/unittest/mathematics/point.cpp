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
#include "../../../src/mathematics/point.hpp"
#include "../../../ext/catch/single_include/catch.hpp"
using toygine::math::point;

TEST_CASE("Point tests", "[PointTests]") {
  const point testPoint1(11, -12);
  const point testPoint2({-12, 22});

  SECTION("addAssign") {
    point p1 = testPoint1;
    point p2 = testPoint2;

    REQUIRE((p1 + testPoint2).x == -1);
    REQUIRE((p1 + testPoint2).y == 10);
    REQUIRE((p2 + testPoint1).x == -1);
    REQUIRE((p2 + testPoint1).y == 10);

    p1 += testPoint2;
    p2 += testPoint1;

    REQUIRE(p1.x == -1);
    REQUIRE(p1.y == 10);
    REQUIRE(p2.x == -1);
    REQUIRE(p2.y == 10);
  }
  SECTION("subAssign") {
    point p1 = testPoint1;
    point p2 = testPoint2;

    REQUIRE((p1 - testPoint2).x == 23);
    REQUIRE((p1 - testPoint2).y == -34);
    REQUIRE((p2 - testPoint1).x == -23);
    REQUIRE((p2 - testPoint1).y == 34);

    p1 -= testPoint2;
    p2 -= testPoint1;

    REQUIRE(p1.x == 23);
    REQUIRE(p1.y == -34);
    REQUIRE(p2.x == -23);
    REQUIRE(p2.y == 34);
  }
  SECTION("mulAssign") {
    point p1 = testPoint1;
    point p2 = testPoint2;

    REQUIRE((p1 * 5).x == 55);
    REQUIRE((p1 * 5).y == -60);
    REQUIRE((p2 * -2).x == 24);
    REQUIRE((p2 * -2).y == -44);

    REQUIRE((5 * p1).x == 55);
    REQUIRE((5 * p1).y == -60);
    REQUIRE((-2 * p2).x == 24);
    REQUIRE((-2 * p2).y == -44);

    p1 *= 5;
    p2 *= -2;

    REQUIRE(p1.x == 55);
    REQUIRE(p1.y == -60);
    REQUIRE(p2.x == 24);
    REQUIRE(p2.y == -44);

    REQUIRE((p1 * -2.15f).x == -118);
    REQUIRE((p1 * -2.15f).y == 129);
    REQUIRE((p2 * 0.25f).x == 6);
    REQUIRE((p2 * 0.25f).y == -11);

    p1 *= -2.15f;
    p2 *= 0.25f;

    REQUIRE(p1.x == -118);
    REQUIRE(p1.y == 129);
    REQUIRE(p2.x == 6);
    REQUIRE(p2.y == -11);
  }
  SECTION("divAssign") {
    point p1 = testPoint1;
    point p2 = testPoint2;

    REQUIRE((p1 / 2).x == 5);
    REQUIRE((p1 / 2).y == -6);
    REQUIRE((p2 / -2).x == 6);
    REQUIRE((p2 / -2).y == -11);

    p1 /= 2;
    p2 /= -2;

    REQUIRE(p1.x == 5);
    REQUIRE(p1.y == -6);
    REQUIRE(p2.x == 6);
    REQUIRE(p2.y == -11);
  }
  SECTION("sqrMagnitude") {
    REQUIRE(testPoint1.sqrMagnitude() == 265);
    REQUIRE(testPoint2.sqrMagnitude() == 628);
  }
  SECTION("setZero") {
    point p1 = testPoint1;
    point p2 = testPoint2;

    REQUIRE(p1.x != 0);
    REQUIRE(p1.y != 0);
    REQUIRE(p2.x != 0);
    REQUIRE(p2.y != 0);

    p1.setZero();
    p2.setZero();

    REQUIRE(p1.x == 0);
    REQUIRE(p1.y == 0);
    REQUIRE(p2.x == 0);
    REQUIRE(p2.y == 0);
  }
  SECTION("isZero") {
    static const std::int32_t arr[] = {0, 0};
    point p1 = testPoint1;
    point p2(arr);

    REQUIRE(!p1.isZero());
    REQUIRE(p2.isZero());

    p1.x = p1.y = 0;

    REQUIRE(p1.isZero());
  }
  SECTION("isEqual") {
    point p1 = testPoint1;
    point p2 = testPoint1;

    REQUIRE(p1.isEqual(p2));

    p2.x += 3;

    REQUIRE(!p1.isEqual(p2));
    REQUIRE(p1.isEqual(p2, 3));
  }
  SECTION("minus") {
    point p1 = -testPoint1;

    REQUIRE(p1.x != testPoint1.x);
    REQUIRE(p1.y != testPoint1.y);

    REQUIRE(-p1.x == testPoint1.x);
    REQUIRE(-p1.y == testPoint1.y);
  }
  SECTION("equaling") {
    point p1 = testPoint1;
    point p2 = testPoint2;

    REQUIRE(p1 == testPoint1);
    REQUIRE(p2 == testPoint2);

    REQUIRE(testPoint1 != testPoint2);
    REQUIRE(p1 != p2);
  }
}
