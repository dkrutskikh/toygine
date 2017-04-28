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

TEST_CASE("Core hashes tests") {
  static const std::string sc_hashString = "ToyGine2 - Free 2D/3D game engine.";

  SECTION("crc8") {
    REQUIRE(crc8(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                 sc_hashString.length()) == 0x95);

    REQUIRE(crc8(nullptr, 0) == 0x00);
    REQUIRE(crc8(reinterpret_cast<const byte *>(sc_hashString.c_str()), 0) ==
            0x00);
    REQUIRE(crc8(nullptr, sc_hashString.length()) == 0x00);

    const std::size_t firstSize =
        static_cast<std::size_t>(std::rand() % sc_hashString.length());

    std::uint8_t testCrc =
        crc8(reinterpret_cast<const byte *>(sc_hashString.c_str()), firstSize);
    testCrc =
        crc8(reinterpret_cast<const byte *>(sc_hashString.c_str()) + firstSize,
             sc_hashString.length() - firstSize, testCrc);

    REQUIRE(crc8(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                 sc_hashString.length()) == testCrc);
  }
  SECTION("crc16") {
    REQUIRE(crc16(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                  sc_hashString.length()) == 0x8A97);

    REQUIRE(crc16(nullptr, 0) == 0x00);
    REQUIRE(crc16(reinterpret_cast<const byte *>(sc_hashString.c_str()), 0) ==
            0x00);
    REQUIRE(crc16(nullptr, sc_hashString.length()) == 0x00);

    const std::size_t firstSize =
        static_cast<std::size_t>(std::rand() % sc_hashString.length());

    std::uint16_t testCrc =
        crc16(reinterpret_cast<const byte *>(sc_hashString.c_str()), firstSize);
    testCrc =
        crc16(reinterpret_cast<const byte *>(sc_hashString.c_str()) + firstSize,
              sc_hashString.length() - firstSize, testCrc);

    REQUIRE(crc16(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                  sc_hashString.length()) == testCrc);
  }
  SECTION("crc32") {
    REQUIRE(crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                  sc_hashString.length()) == 0xF003D128);

    REQUIRE(crc32(nullptr, 0) == 0x00);
    REQUIRE(crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()), 0) ==
            0x00);
    REQUIRE(crc32(nullptr, sc_hashString.length()) == 0x00);

    const std::size_t firstSize =
        static_cast<std::size_t>(std::rand() % sc_hashString.length());

    std::uint32_t testCrc =
        crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()), firstSize);
    testCrc =
        crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()) + firstSize,
              sc_hashString.length() - firstSize, testCrc);

    REQUIRE(crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                  sc_hashString.length()) == testCrc);
  }
}
