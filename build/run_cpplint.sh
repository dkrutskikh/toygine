#!/bin/sh

CHECK_DIRS="./include ./src ./test"

#--------------

CPPLINT_FILES=`find $CHECK_DIRS -name "*.cpp" -o -name "*.hpp" -o -name "*.inl" -o -name "*.c" -o -name "*.h"`
echo $CPPLINT_FILES | xargs python ext/googlestyleguide/cpplint/cpplint.py 2>&1

#--------------

exit 0
