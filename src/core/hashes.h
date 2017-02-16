/*
  \file   hashes.h
  \brief  hash functions
*/

#ifndef INCLUDE_HASHES_H_
#define INCLUDE_HASHES_H_

#include "../../include/core.h"

namespace toygine {

uint8 crc8(const byte *data, size_t size, uint8 crc = 0);
uint16 crc16(const byte *data, size_t size, uint16 crc = 0);
uint32 crc32(const byte *data, size_t size, uint32 crc = 0);

}  // namespace toygine

#endif  // INCLUDE_HASHES_H_
