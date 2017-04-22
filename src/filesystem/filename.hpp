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
  inline filename();
  inline ~filename();

  inline filename(filename &&instance);
  inline filename(const filename &instance);
  inline explicit filename(std::string &&fileName);
  inline explicit filename(const std::string &fileName);
  inline explicit filename(const char *fileName);

  inline bool empty() const;

  inline const std::string &fullPath() const;
  inline std::string path() const;
  std::string nameExt() const;
  std::string name() const;
  std::string ext() const;

  inline void setExtension(const std::string &newExtension);
  void setExtension(char const *newExtension);

  inline filename &operator=(filename &&instance);
  inline filename &operator=(const filename &instance);
  inline filename &operator=(std::string &&str);
  inline filename &operator=(const std::string &str);
  inline filename &operator=(char const *s);

  inline filename &operator+=(const filename &instance);
  filename &operator+=(const std::string &str);
  inline filename &operator+=(char const *s);

  void dirUp();

 private:
  void fix();
  void optimize();

  std::string _fileName;
};

inline bool operator==(const filename &lhs, const filename &rhs);
inline bool operator==(const filename &lhs, const std::string &rhs);
inline bool operator==(const std::string &lhs, const filename &rhs);
inline bool operator==(const filename &lhs, const char *rhs);
inline bool operator==(const char *&lhs, const filename &rhs);

inline bool operator!=(const filename &lhs, const filename &rhs);
inline bool operator!=(const filename &lhs, const std::string &rhs);
inline bool operator!=(const std::string &lhs, const filename &rhs);
inline bool operator!=(const filename &lhs, const char *rhs);
inline bool operator!=(const char *&lhs, const filename &rhs);

}  // namespace filesystem
}  // namespace toygine

#include "filename.inl"

#endif  // SRC_FILESYSTEM_FILENAME_HPP_
