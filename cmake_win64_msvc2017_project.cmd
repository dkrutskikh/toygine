set OUTPUT_DIR_NAME=garbage

rem --------------

md %OUTPUT_DIR_NAME%
cd %OUTPUT_DIR_NAME%

rem --------------

cmake.exe -G "Visual Studio 15 2017 Win64" ".."

rem --------------
