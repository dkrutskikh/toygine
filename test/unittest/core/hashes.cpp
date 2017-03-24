#include "../../../ext/catch/single_include/catch.hpp"
#include "../../../src/core/hashes.h"
using namespace toygine;

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
        static_cast<size_t>(rand() % sc_hashString.length());

    uint32 testCrc =
        crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()), firstSize);
    testCrc =
        crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()) + firstSize,
              sc_hashString.length() - firstSize, testCrc);

    REQUIRE(crc32(reinterpret_cast<const byte *>(sc_hashString.c_str()),
                  sc_hashString.length()) == testCrc);
  }
}
