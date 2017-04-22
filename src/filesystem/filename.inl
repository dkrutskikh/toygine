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

inline filename::filename() : _fileName() {}

inline filename::~filename() {}

inline filename::filename(filename &&instance)
    : _fileName(instance._fileName) {}

inline filename::filename(const filename &instance)
    : _fileName(instance._fileName) {}

inline filename::filename(std::string &&fileName) : _fileName(fileName) {
  fix();
  optimize();
}

inline filename::filename(const std::string &fileName) : _fileName(fileName) {
  fix();
  optimize();
}

inline filename::filename(const char *fileName) : _fileName(fileName) {
  fix();
  optimize();
}

inline bool filename::empty() const { return _fileName.empty(); }

inline const std::string &filename::fullPath() const { return _fileName; }

inline std::string filename::path() const {
  return _fileName.substr(0, _fileName.size() - nameExt().length());
}

inline void filename::setExtension(const std::string &newExtension) {
  setExtension(newExtension.c_str());
}

inline filename &filename::operator=(filename &&instance) {
  std::swap(_fileName, instance._fileName);
  return *this;
}

inline filename &filename::operator=(const filename &instance) {
  _fileName = instance._fileName;
  return *this;
}

inline filename &filename::operator=(std::string &&str) {
  std::swap(_fileName, str);
  fix();
  optimize();
  return *this;
}

inline filename &filename::operator=(const std::string &str) {
  _fileName = str;
  fix();
  optimize();
  return *this;
}

inline filename &filename::operator=(const char *s) {
  assert(s != nullptr);
  _fileName = s;
  fix();
  optimize();
  return *this;
}

inline filename &filename::operator+=(const filename &instance) {
  return *this += instance.fullPath();
}

inline filename &filename::operator+=(const char *s) {
  assert(s != nullptr);
  return *this += std::string(s);
}

inline bool operator==(const filename &lhs, const filename &rhs) {
  return lhs.fullPath() == rhs.fullPath();
}

inline bool operator==(const filename &lhs, const std::string &rhs) {
  return lhs.fullPath() == rhs;
}

inline bool operator==(const std::string &lhs, const filename &rhs) {
  return rhs == lhs;
}

inline bool operator==(const filename &lhs, const char *rhs) {
  assert(rhs != nullptr);
  return lhs.fullPath() == rhs;
}

inline bool operator==(const char *lhs, const filename &rhs) {
  return rhs == lhs;
}

inline bool operator!=(const filename &lhs, const filename &rhs) {
  return !(lhs == rhs);
}

inline bool operator!=(const filename &lhs, const std::string &rhs) {
  return !(lhs == rhs);
}

inline bool operator!=(const std::string &lhs, const filename &rhs) {
  return !(lhs == rhs);
}

inline bool operator!=(const filename &lhs, const char *rhs) {
  return !(lhs == rhs);
}

inline bool operator!=(const char *lhs, const filename &rhs) {
  return rhs != lhs;
}

}  // namespace filesystem
}  // namespace toygine

#endif  // SRC_FILESYSTEM_FILENAME_INL_
