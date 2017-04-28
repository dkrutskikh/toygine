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

#ifndef SRC_FILESYSTEM_FILENAME_INL_
#define SRC_FILESYSTEM_FILENAME_INL_

#include <cassert>

namespace toygine {
namespace filesystem {

inline filename::filename() noexcept : _fileName() {}

inline filename::~filename() noexcept {}

inline filename::filename(filename &&instance) noexcept
    : _fileName(instance._fileName) {}

inline filename::filename(const filename &instance) noexcept
    : _fileName(instance._fileName) {}

inline filename::filename(std::string &&fileName) noexcept
    : _fileName(fileName) {
  fix();
  optimize();
}

inline filename::filename(const std::string &fileName) noexcept
    : _fileName(fileName) {
  fix();
  optimize();
}

inline filename::filename(const char *fileName) noexcept : _fileName(fileName) {
  fix();
  optimize();
}

inline bool filename::empty() const noexcept { return _fileName.empty(); }

inline const std::string &filename::fullPath() const noexcept {
  return _fileName;
}

inline std::string filename::path() const noexcept {
  return _fileName.substr(0, _fileName.size() - nameExt().length());
}

inline void filename::setExtension(const std::string &newExtension) noexcept {
  setExtension(newExtension.c_str());
}

inline filename &filename::operator=(filename &&instance) noexcept {
  std::swap(_fileName, instance._fileName);
  return *this;
}

inline filename &filename::operator=(const filename &instance) noexcept {
  _fileName = instance._fileName;
  return *this;
}

inline filename &filename::operator=(std::string &&str) noexcept {
  std::swap(_fileName, str);
  fix();
  optimize();
  return *this;
}

inline filename &filename::operator=(const std::string &str) noexcept {
  _fileName = str;
  fix();
  optimize();
  return *this;
}

inline filename &filename::operator=(const char *s) noexcept {
  assert(s != nullptr);
  _fileName = s;
  fix();
  optimize();
  return *this;
}

inline filename &filename::operator+=(const filename &instance) noexcept {
  return *this += instance.fullPath();
}

inline filename &filename::operator+=(const char *s) noexcept {
  assert(s != nullptr);
  return *this += std::string(s);
}

inline bool operator==(const filename &lhs, const filename &rhs) noexcept {
  return lhs.fullPath() == rhs.fullPath();
}

inline bool operator==(const filename &lhs, const std::string &rhs) noexcept {
  return lhs.fullPath() == rhs;
}

inline bool operator==(const std::string &lhs, const filename &rhs) noexcept {
  return rhs == lhs;
}

inline bool operator==(const filename &lhs, const char *rhs) noexcept {
  assert(rhs != nullptr);
  return lhs.fullPath() == rhs;
}

inline bool operator==(const char *lhs, const filename &rhs) noexcept {
  return rhs == lhs;
}

inline bool operator!=(const filename &lhs, const filename &rhs) noexcept {
  return !(lhs == rhs);
}

inline bool operator!=(const filename &lhs, const std::string &rhs) noexcept {
  return !(lhs == rhs);
}

inline bool operator!=(const std::string &lhs, const filename &rhs) noexcept {
  return !(lhs == rhs);
}

inline bool operator!=(const filename &lhs, const char *rhs) noexcept {
  return !(lhs == rhs);
}

inline bool operator!=(const char *lhs, const filename &rhs) noexcept {
  return rhs != lhs;
}

}  // namespace filesystem
}  // namespace toygine

#endif  // SRC_FILESYSTEM_FILENAME_INL_
