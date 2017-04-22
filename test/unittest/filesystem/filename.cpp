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
#include "../../../src/filesystem/filename.hpp"
#include <string>
#include "../../../ext/catch/single_include/catch.hpp"
using toygine::filesystem::filename;

TEST_CASE("Filename tests", "[FilenameTests]") {
  static const std::string fn1_s = "S:/path/folder/filename.ext";
  static const std::string fn1_2_s = "s:\\path\\folder\\filename.ext";
  static const std::string fn2_s = "folder/filename.ext";
  static const std::string fn2_2_s = "folder\\filename.ext";
  static const std::string fn3_s = "filename.ext";
  static const std::string fn4_s = "./path/my.folder/filename";
  static const std::string fn5_s = "./";

  const filename testFN;
  const filename testFN1(fn1_s);
  const filename testFN1_2(fn1_2_s);
  const filename testFN2(fn2_s);
  const filename testFN2_2(fn2_2_s);
  const filename testFN3(fn3_s);
  const filename testFN4(fn4_s);
  const filename testFN5(fn5_s);

  SECTION("empty") {
    REQUIRE(testFN.empty());
    REQUIRE_FALSE(testFN1.empty());
    REQUIRE_FALSE(testFN1_2.empty());
    REQUIRE_FALSE(testFN2.empty());
    REQUIRE_FALSE(testFN2_2.empty());
    REQUIRE_FALSE(testFN3.empty());
    REQUIRE_FALSE(testFN4.empty());
    REQUIRE(testFN5.empty());
  }
  SECTION("fullPath") {
    REQUIRE(testFN.fullPath().empty());
    REQUIRE(testFN1.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(testFN1_2.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(testFN2.fullPath() == "folder/filename.ext");
    REQUIRE(testFN2_2.fullPath() == "folder/filename.ext");
    REQUIRE(testFN3.fullPath() == "filename.ext");
    REQUIRE(testFN4.fullPath() == "path/my.folder/filename");
    REQUIRE(testFN5.fullPath().empty());
  }
  SECTION("path") {
    REQUIRE(testFN.path().empty());
    REQUIRE(testFN1.path() == "S:/path/folder/");
    REQUIRE(testFN1_2.path() == "S:/path/folder/");
    REQUIRE(testFN2.path() == "folder/");
    REQUIRE(testFN2_2.path() == "folder/");
    REQUIRE(testFN3.path().empty());
    REQUIRE(testFN4.path() == "path/my.folder/");
    REQUIRE(testFN5.path().empty());
  }
  SECTION("nameExt") {
    REQUIRE(testFN.nameExt().empty());
    REQUIRE(testFN1.nameExt() == "filename.ext");
    REQUIRE(testFN1_2.nameExt() == "filename.ext");
    REQUIRE(testFN2.nameExt() == "filename.ext");
    REQUIRE(testFN2_2.nameExt() == "filename.ext");
    REQUIRE(testFN3.nameExt() == "filename.ext");
    REQUIRE(testFN4.nameExt() == "filename");
    REQUIRE(testFN5.nameExt().empty());
  }
  SECTION("name") {
    REQUIRE(testFN.name().empty());
    REQUIRE(testFN1.name() == "filename");
    REQUIRE(testFN1_2.name() == "filename");
    REQUIRE(testFN2.name() == "filename");
    REQUIRE(testFN2_2.name() == "filename");
    REQUIRE(testFN3.name() == "filename");
    REQUIRE(testFN4.name() == "filename");
    REQUIRE(testFN5.name().empty());
  }
  SECTION("ext") {
    REQUIRE(testFN.ext().empty());
    REQUIRE(testFN1.ext() == "ext");
    REQUIRE(testFN1_2.ext() == "ext");
    REQUIRE(testFN2.ext() == "ext");
    REQUIRE(testFN2_2.ext() == "ext");
    REQUIRE(testFN3.ext() == "ext");
    REQUIRE(testFN4.ext().empty());
    REQUIRE(testFN5.ext().empty());
  }
  SECTION("setExtension") {
    auto fn = testFN;
    auto fn1 = testFN1;
    auto fn1_2 = testFN1_2;
    auto fn2 = testFN2;
    auto fn2_2 = testFN2_2;
    auto fn3 = testFN3;
    auto fn4 = testFN4;
    auto fn5 = testFN5;

    REQUIRE(fn.fullPath().empty());
    REQUIRE(fn1.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(fn1_2.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(fn2.fullPath() == "folder/filename.ext");
    REQUIRE(fn2_2.fullPath() == "folder/filename.ext");
    REQUIRE(fn3.fullPath() == "filename.ext");
    REQUIRE(fn4.fullPath() == "path/my.folder/filename");
    REQUIRE(fn5.fullPath().empty());

    fn.setExtension(std::string("ext"));
    fn1.setExtension(std::string("ext1"));
    fn1_2.setExtension(std::string(".ext1_2"));
    fn2.setExtension(std::string(".ext2"));
    fn2_2.setExtension("");
    fn3.setExtension("ext3");
    fn4.setExtension(".ext4");
    fn5.setExtension(".ext5");

    REQUIRE(fn.fullPath().empty());
    REQUIRE(fn1.fullPath() == "S:/path/folder/filename.ext1");
    REQUIRE(fn1_2.fullPath() == "S:/path/folder/filename.ext1_2");
    REQUIRE(fn2.fullPath() == "folder/filename.ext2");
    REQUIRE(fn2_2.fullPath() == "folder/filename");
    REQUIRE(fn3.fullPath() == "filename.ext3");
    REQUIRE(fn4.fullPath() == "path/my.folder/filename.ext4");
    REQUIRE(fn5.fullPath().empty());
  }
  SECTION("dirUp") {
    auto fn = testFN;
    auto fn1 = testFN1;
    auto fn1_2 = testFN1_2;
    auto fn2 = testFN2;
    auto fn2_2 = testFN2_2;
    auto fn3 = testFN3;
    auto fn4 = testFN4;
    auto fn5 = testFN5;

    REQUIRE(fn.fullPath().empty());
    REQUIRE(fn1.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(fn1_2.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(fn2.fullPath() == "folder/filename.ext");
    REQUIRE(fn2_2.fullPath() == "folder/filename.ext");
    REQUIRE(fn3.fullPath() == "filename.ext");
    REQUIRE(fn4.fullPath() == "path/my.folder/filename");
    REQUIRE(fn5.fullPath().empty());

    fn.dirUp();
    fn1.dirUp();
    fn1_2.dirUp();
    fn2.dirUp();
    fn2_2.dirUp();
    fn3.dirUp();
    fn4.dirUp();
    fn5.dirUp();

    REQUIRE(fn.fullPath().empty());
    REQUIRE(fn1.fullPath() == "S:/path/");
    REQUIRE(fn1_2.fullPath() == "S:/path/");
    REQUIRE(fn2.fullPath() == "folder/");
    REQUIRE(fn2_2.fullPath() == "folder/");
    REQUIRE(fn3.fullPath().empty());
    REQUIRE(fn4.fullPath() == "path/");
    REQUIRE(fn5.fullPath().empty());

    fn1.dirUp();
    fn1_2.dirUp();
    fn2.dirUp();
    fn2_2.dirUp();
    fn3.dirUp();
    fn4.dirUp();

    REQUIRE(fn1.fullPath() == "S:/");
    REQUIRE(fn1_2.fullPath() == "S:/");
    REQUIRE(fn2.fullPath() == "folder/");
    REQUIRE(fn2_2.fullPath() == "folder/");
    REQUIRE(fn3.fullPath().empty());
    REQUIRE(fn4.fullPath() == "path/");

    fn1.dirUp();
    fn1_2.dirUp();

    REQUIRE(fn1.fullPath() == "S:/");
    REQUIRE(fn1_2.fullPath() == "S:/");
  }
  SECTION("assign") {
    filename fn1;
    filename fn1_2;
    filename fn2;
    filename fn2_2;
    filename fn3;

    REQUIRE(fn1.fullPath().empty());
    REQUIRE(fn1_2.fullPath().empty());
    REQUIRE(fn2.fullPath().empty());
    REQUIRE(fn2_2.fullPath().empty());
    REQUIRE(fn3.fullPath().empty());

    fn1 = filename("S:/path/../path/folder/./filename.ext");
    fn1_2 = testFN1_2;
    fn2 = std::string("folder//filename.ext");
    fn2_2 = fn2_2_s;
    fn3 = "./filename.ext";

    REQUIRE(fn1.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(fn1_2.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(fn2.fullPath() == "folder/filename.ext");
    REQUIRE(fn2_2.fullPath() == "folder/filename.ext");
    REQUIRE(fn3.fullPath() == "filename.ext");
  }
  SECTION("addAssign") {
    filename fn1 = filename(testFN1.path());
    filename fn1_2 = filename(testFN1_2.path());
    filename fn2 = filename(testFN2.path());
    filename fn3 = filename("folder");
    filename fn4;

    fn1 += testFN3;
    fn1_2 += fn3_s;
    fn2 += fn3_s;
    fn3 += "filename.ext";
    fn4 += "filename.ext";

    REQUIRE(fn1.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(fn1_2.fullPath() == "S:/path/folder/filename.ext");
    REQUIRE(fn2.fullPath() == "folder/filename.ext");
    REQUIRE(fn3.fullPath() == "folder/filename.ext");
    REQUIRE(fn4.fullPath() == "filename.ext");
  }
  SECTION("equality") {
    REQUIRE(testFN1 == testFN1_2);
    REQUIRE(testFN2 == fn2_s);
    REQUIRE(fn2_s == testFN2);
    REQUIRE(testFN3 == "filename.ext");
    REQUIRE("filename.ext" == testFN3);

    REQUIRE_FALSE(testFN1 == testFN2);
    REQUIRE_FALSE(testFN2 == fn1_s);
    REQUIRE_FALSE(fn1_s == testFN2);
    REQUIRE_FALSE(testFN2_2 == "filename.ext");
    REQUIRE_FALSE("filename.ext" == testFN2_2);
  }
  SECTION("inequality") {
    REQUIRE(testFN1 != testFN2);
    REQUIRE(testFN2 != fn1_s);
    REQUIRE(fn1_s != testFN2);
    REQUIRE(testFN2_2 != "filename.ext");
    REQUIRE("filename.ext" != testFN2_2);

    REQUIRE_FALSE(testFN1 != testFN1_2);
    REQUIRE_FALSE(testFN2 != fn2_s);
    REQUIRE_FALSE(fn2_s != testFN2);
    REQUIRE_FALSE(testFN3 != "filename.ext");
    REQUIRE_FALSE("filename.ext" != testFN3);
  }
}
