#!/bin/bash
cmake -version
SOURCE_DIR=source
BUILD_DIR=build
mkdir -p $BUILD_DIR && rm -rf $BUILD_DIR/* && cd $BUILD_DIR && cmake ../$SOURCE_DIR && cmake build . && gmake
echo -e "Build result : {$?}" 
cd -
