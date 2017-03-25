#!/bin/sh

CHECK_DIRS="./include ./samples ./src ./tests ./tools"

#--------------

CPPLINT_FILES=`find $CHECK_DIRS -name "*.cpp" -o -name "*.h" -o -name "*.inl" -o -name "*.c"`
echo $CPPLINT_FILES | xargs python ext/googlestyleguide/cpplint/cpplint.py 2>&1

#--------------

exit 0
