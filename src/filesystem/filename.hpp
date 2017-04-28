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
/*
  \file   filename.hpp
  \brief
*/

#ifndef SRC_FILESYSTEM_FILENAME_HPP_
#define SRC_FILESYSTEM_FILENAME_HPP_

#include <string>

namespace toygine {
namespace filesystem {

class filename {
 public:
  inline filename() noexcept;
  inline ~filename() noexcept;

  inline filename(filename &&instance) noexcept;
  inline filename(const filename &instance) noexcept;
  inline explicit filename(std::string &&fileName) noexcept;
  inline explicit filename(const std::string &fileName) noexcept;
  inline explicit filename(const char *fileName) noexcept;

  inline bool empty() const noexcept;

  inline const std::string &fullPath() const noexcept;
  inline std::string path() const noexcept;
  std::string nameExt() const noexcept;
  std::string name() const noexcept;
  std::string ext() const noexcept;

  inline void setExtension(const std::string &newExtension) noexcept;
  void setExtension(char const *newExtension) noexcept;

  inline filename &operator=(filename &&instance) noexcept;
  inline filename &operator=(const filename &instance) noexcept;
  inline filename &operator=(std::string &&str) noexcept;
  inline filename &operator=(const std::string &str) noexcept;
  inline filename &operator=(char const *s) noexcept;

  inline filename &operator+=(const filename &instance) noexcept;
  filename &operator+=(const std::string &str) noexcept;
  inline filename &operator+=(char const *s) noexcept;

  void dirUp() noexcept;

 private:
  void fix() noexcept;
  void optimize() noexcept;

  std::string _fileName;
};

inline bool operator==(const filename &lhs, const filename &rhs) noexcept;
inline bool operator==(const filename &lhs, const std::string &rhs) noexcept;
inline bool operator==(const std::string &lhs, const filename &rhs) noexcept;
inline bool operator==(const filename &lhs, const char *rhs) noexcept;
inline bool operator==(const char *&lhs, const filename &rhs) noexcept;

inline bool operator!=(const filename &lhs, const filename &rhs) noexcept;
inline bool operator!=(const filename &lhs, const std::string &rhs) noexcept;
inline bool operator!=(const std::string &lhs, const filename &rhs) noexcept;
inline bool operator!=(const filename &lhs, const char *rhs) noexcept;
inline bool operator!=(const char *&lhs, const filename &rhs) noexcept;

}  // namespace filesystem
}  // namespace toygine

#include "filename.inl"

#endif  // SRC_FILESYSTEM_FILENAME_HPP_
