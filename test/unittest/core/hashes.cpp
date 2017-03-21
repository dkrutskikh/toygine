#include "../../../ext/catch/single_include/catch.hpp"
#include "../../../src/core/hashes.h"
using namespace toygine;


TEST_CASE("Hashes tests", "[HashesTests]") {

  static const char *sc_hashString = "ToyGine2 - Free 2D/3D game engine.";

  SECTION("crc8") {
    REQUIRE(crc8(reinterpret_cast< const byte * >(sc_hashString), strlen(sc_hashString)) == 0x6A);
  }
  SECTION("crc16") {
    REQUIRE(crc16(reinterpret_cast< const byte * >(sc_hashString), strlen(sc_hashString)) == 0x7568);
  }
  SECTION("crc32") {
    REQUIRE(crc32(reinterpret_cast< const byte * >(sc_hashString), strlen(sc_hashString)) == 0xF003D128);

    const size_t firstSize = static_cast< size_t >(rand() % strlen(sc_hashString));

    uint32 testCrc = crc32(reinterpret_cast< const byte * >(sc_hashString), firstSize);
    testCrc = crc32(reinterpret_cast< const byte * >(sc_hashString) + firstSize, strlen(sc_hashString) - firstSize, testCrc);

    REQUIRE(crc32(reinterpret_cast< const byte * >(sc_hashString), strlen(sc_hashString)) == testCrc);
  }
}
