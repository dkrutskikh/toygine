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
#include "filename.hpp"
#include <string>

namespace toygine {
namespace filesystem {

void filename::fix() {
  for (std::size_t index = 0; index < _fileName.size(); ++index) {
    if (_fileName[index] == '\\') _fileName[index] = '/';
  }

  if (_fileName.size() >= 3 && _fileName[1] == ':' && _fileName[2] == '/' &&
      (_fileName.front() >= 'a' && _fileName.front() <= 'z'))
    _fileName.front() -= ('a' - 'A');
}

std::string filename::nameExt() const {
  if (_fileName.empty()) return fullPath();

  auto index = _fileName.find_last_of('/');
  if (index == std::string::npos) return fullPath();

  return fullPath().substr(index + 1);
}

std::string filename::name() const {
  auto nameExtSize = nameExt().length();
  if (nameExtSize == 0) return "";

  auto extSize = ext().length();
  if (extSize > 0) extSize++;

  return _fileName.substr(_fileName.size() - nameExtSize,
                          nameExtSize - extSize);
}

std::string filename::ext() const {
  auto fileNameExt = nameExt();
  auto index = fileNameExt.find_last_of('.');
  if (index == std::string::npos) return "";

  return fileNameExt.substr(index + 1);
}

void filename::setExtension(char const *newExtension) {
  assert(newExtension != nullptr);
  if (nameExt().empty()) return;

  auto oldExtLen = ext().length();
  if (oldExtLen > 0) _fileName.erase(_fileName.size() - oldExtLen - 1);

  if (*newExtension == '\0') return;

  if (*newExtension != '.') _fileName += '.';

  _fileName += newExtension;
}

void filename::dirUp() {
  if (_fileName.size() < 2) return;

  _fileName.erase(_fileName.size() - nameExt().length());
  auto prevSlash = _fileName.find_last_of('/', _fileName.size() - 2);
  if (prevSlash != std::string::npos) _fileName.erase(prevSlash + 1);
}

filename &filename::operator+=(const std::string &str) {
  if (str.empty()) return *this;

  if (_fileName.empty()) {
    _fileName = str;
  } else {
    _fileName.reserve(_fileName.size() + str.size() + 1);

    // add '/' if not present at the end of original part and at the start
    // additional part
    if (_fileName.back() != '/' && (str.front() != '/' && str.front() != '\\'))
      _fileName += '/';

    _fileName += str;
  }

  fix();
  optimize();

  return *this;
}

void filename::optimize() {
  // kill first "./"
  if (_fileName.size() > 1 && _fileName.front() == '.' && _fileName[1] == '/')
    _fileName.erase(0, 2);

  size_t index = 0;

  // kill "//"
  while ((index = _fileName.find("//")) != std::string::npos)
    _fileName.erase(index, 1);

  // kill "." dir
  while ((index = _fileName.find("/./")) != std::string::npos)
    _fileName.erase(index, 2);

  // kill "/xxx/../"
  size_t offset = 0;
  while ((index = _fileName.find("/../", offset)) != std::string::npos) {
    assert(index > 0);
    size_t scanIndex = index;
    offset = index + 3;

    while (scanIndex > 0) {
      --scanIndex;
      if (_fileName[scanIndex] == '/') {
        if (index - scanIndex > 3) {
          _fileName.erase(scanIndex, index - scanIndex + 3);
          offset = 0;
          break;
        }
      }
    }
  }
}

}  // namespace filesystem
}  // namespace toygine
