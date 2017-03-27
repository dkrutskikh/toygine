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
#include "../../../src/core/hashes.hpp"
#include <cstdlib>
#include <string>
#include "../../../ext/catch/single_include/catch.hpp"
using toygine::crc8;
using toygine::crc16;
using toygine::crc32;

TEST_CASE("Hashes tests", "[HashesTests]") {
  static const std::string sc_hashString = "ToyGine2 - Free 2D/3D game engine.";

  SECTION("crc8") {
    REQUIRE(crc8(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                 sc_hashString.length()) == 0x6A);
  }
  SECTION("crc16") {
    REQUIRE(crc16(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                  sc_hashString.length()) == 0x7568);
  }
  SECTION("crc32") {
    REQUIRE(crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                  sc_hashString.length()) == 0xF003D128);

    const size_t firstSize =
        static_cast<size_t>(std::rand() % sc_hashString.length());

    std::uint32_t testCrc =
        crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()), firstSize);
    testCrc =
        crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()) + firstSize,
              sc_hashString.length() - firstSize, testCrc);

    REQUIRE(crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                  sc_hashString.length()) == testCrc);
  }
}
