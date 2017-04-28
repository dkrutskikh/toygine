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
#include "app.hpp"
#include <chrono>
#include <thread>

namespace toygine {

static app *s_instance = nullptr;

app::app() : _version(), _exitStatus(true) { s_instance = this; }

app::~app() { s_instance = nullptr; }

void app::setVersion(std::uint32_t major, std::uint32_t minor,
                     std::uint32_t patch) {
  _version.major = major;
  _version.minor = minor;
  _version.patch = patch;
}

app *app::instance() { return s_instance; }

bool app::initialize() {
  return true;
}

bool app::process() {
  return false;
}

void app::shutdown() {
}

bool app::run() {
  using namespace std::chrono_literals;

  if (!initialize())
    return false;

  while (process())
    std::this_thread::sleep_for(1ms);

  shutdown();
  return true;
}

} // namespace toygine
