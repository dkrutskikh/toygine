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
/*!
\file   app.hpp
\brief
*/

#ifndef PLAYER_APP_HPP_
#define PLAYER_APP_HPP_

#include <cstdint>
#include <vector>

namespace toygine {

struct semversion {
  std::uint32_t major;
  std::uint32_t minor;
  std::uint32_t patch;

  inline semversion();
};

class app {
public:
  app();
  ~app();

  inline const semversion &version() const;
  void setVersion(std::uint32_t major, std::uint32_t minor = 0,
                  std::uint32_t patch = 0);

  //  static std::uint32_t pid();
  //  static void sleep(size_t milliseconds);
  static app *instance();

  bool initialize();
  bool process();
  void shutdown();

  bool run();
  inline bool exitStatus() const;

private:
  semversion _version;

  bool _exitStatus;
};

} // namespace toygine

#include "app.inl"

#endif // PLAYER_APP_HPP_
