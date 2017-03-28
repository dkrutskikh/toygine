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

inline file_name::file_name() : _fileName() {}

inline file_name::~file_name() {}

inline file_name::file_name(file_name &&instance)
    : _fileName(instance._fileName) {}

inline file_name::file_name(const file_name &instance)
    : _fileName(instance._fileName) {}

inline file_name::file_name(std::string &&fileName) : _fileName(fileName) {
  fix();
  optimize();
}

inline file_name::file_name(const std::string &fileName) : _fileName(fileName) {
  fix();
  optimize();
}

inline file_name::file_name(const char *fileName) : _fileName(fileName) {
  fix();
  optimize();
}

inline bool file_name::empty() const { return _fileName.empty(); }

inline const std::string &file_name::fullPath() const { return _fileName; }

inline std::string file_name::path() const {
  return _fileName.substr(0, _fileName.size() - nameExt().length());
}

inline void file_name::setExtension(const std::string &newExtension) {
  setExtension(newExtension.c_str());
}

inline file_name &file_name::operator=(file_name &&instance) {
  std::swap(_fileName, instance._fileName);
  return *this;
}

inline file_name &file_name::operator=(const file_name &instance) {
  _fileName = instance._fileName;
  return *this;
}

inline file_name &file_name::operator=(std::string &&str) {
  std::swap(_fileName, str);
  fix();
  optimize();
  return *this;
}

inline file_name &file_name::operator=(const std::string &str) {
  _fileName = str;
  fix();
  optimize();
  return *this;
}

inline file_name &file_name::operator=(const char *s) {
  assert(s != nullptr);
  _fileName = s;
  fix();
  optimize();
  return *this;
}

inline file_name &file_name::operator+=(const file_name &instance) {
  return *this += instance.fullPath();
}

inline file_name &file_name::operator+=(const char *s) {
  assert(s != nullptr);
  return *this += std::string(s);
}

inline bool operator==(const file_name &lhs, const file_name &rhs) {
  return lhs.fullPath() == rhs.fullPath();
}

inline bool operator==(const file_name &lhs, const std::string &rhs) {
  return lhs.fullPath() == rhs;
}

inline bool operator==(const std::string &lhs, const file_name &rhs) {
  return rhs == lhs;
}

inline bool operator==(const file_name &lhs, const char *rhs) {
  assert(rhs != nullptr);
  return lhs.fullPath() == rhs;
}

inline bool operator==(const char *lhs, const file_name &rhs) {
  return rhs == lhs;
}

inline bool operator!=(const file_name &lhs, const file_name &rhs) {
  return !(lhs == rhs);
}

inline bool operator!=(const file_name &lhs, const std::string &rhs) {
  return !(lhs == rhs);
}

inline bool operator!=(const std::string &lhs, const file_name &rhs) {
  return !(lhs == rhs);
}

inline bool operator!=(const file_name &lhs, const char *rhs) {
  return !(lhs == rhs);
}

inline bool operator!=(const char *lhs, const file_name &rhs) {
  return rhs != lhs;
}

}  // namespace filesystem
}  // namespace toygine

#endif  // SRC_FILESYSTEM_FILENAME_INL_
