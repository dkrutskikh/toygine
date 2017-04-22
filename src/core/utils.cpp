//
// Copyright (c) 2016 Toyman Interactive
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not claim
// that you wrote the original software. If you use this software in a product,
// an acknowledgment in the product documentation would be appreciated but is
// not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
#include "utils.hpp"
#include <cstdint>

namespace toygine {

char *ucs2ToUtf8(char *dest, std::size_t destSize, wchar_t const *src) {
  if (dest == nullptr || destSize == 0) return nullptr;

  char *destPointer = dest;
  if (src != nullptr) {
    char const *utf8EndPos = dest + (destSize - 1);

    while (*src && destPointer < utf8EndPos) {
      std::uint32_t symbol = *src++;
      if (symbol <= 0x7F) {
        *destPointer = static_cast<char>(symbol);
      } else {
        if (symbol <= 0x7FF) {
          *destPointer = static_cast<char>((symbol & 0x07C0) >> 6) | 0xC0;
        } else {
          *destPointer = ((symbol & 0xF000) >> 12) | 0xE0;
          ++destPointer;
          *destPointer = static_cast<char>((symbol & 0x0FC0) >> 6) | 0x80;
        }

        ++destPointer;
        *destPointer = (symbol & 0x003F) | 0x80;
      }
      ++destPointer;
    }
  }

  *destPointer = '\0';
  return dest;
}

}  // namespace toygine
