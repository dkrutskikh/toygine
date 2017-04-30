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
#include "../../../src/core/logger.hpp"
#include <string>
#include "../../../ext/catch/single_include/catch.hpp"
using toygine::log::level;

TEST_CASE("Log tests") {
  SECTION("level") {
    SECTION("equaling") {
      level l1 = level::ALL;
      level l3 = level(std::string("TEST ALL LEVEL"), 0);
      level l4 = level("TEST OFF LEVEL", 2000);
      REQUIRE(l1 == level::ALL);
      REQUIRE(l1 != l4);

      REQUIRE(level::INFO < level::WARNING);
      REQUIRE(level::INFO > level::ALL);

      REQUIRE(level::INFO <= level::INFO);
      REQUIRE(level::INFO >= level::INFO);
    }
  }
}
