#!/bin/sh

OUTPUT_DIR_NAME="garbage"

#--------------

rm -dfr "${OUTPUT_DIR_NAME}"
mkdir -pv "${OUTPUT_DIR_NAME}"
cd "${OUTPUT_DIR_NAME}"

#--------------

cmake -G "Xcode" ".."

#--------------

cd ".."

#--------------
