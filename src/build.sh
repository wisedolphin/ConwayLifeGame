#!/bin/bash

CUR_DIR=$(pwd)
BUILD_DIR="tmp_build_dir"
CLEAN_COMMAND="clean"

#if first arg is clean -> clean all build dirs
if [ $1 == $CLEAN_COMMAND ]
then
	echo "!!!!!!!!!!!!!"
	if [ -d "$CUR_DIR/$BUILD_DIR" ]
	then
		echo "Directory $CUR_DIR/$BUILD_DIR exists\n"
		echo "Deliting $CUR_DIR/$BUILD_DIR"
		rm -R "$CUR_DIR/$BUILD_DIR"
	fi
	if [ -f "$CUR_DIR/CMake.log" ]
	then		
		echo "Deliting CMake.log"
		rm -R "$CUR_DIR/CMake.log"
	fi
	if [ -f "$CUR_DIR/Make.log" ]
	then				
		echo "Deliting Make.log"
		rm -R "$CUR_DIR/Make.log"
	fi
	if [ -f "$CUR_DIR/ConwayLifeGame" ]
	then						
		echo "Deliting exe"
		rm -R "$CUR_DIR/ConwayLifeGame"
	fi
	exit 1
fi


#clean build dir before building
if [ -d "$CUR_DIR/$BUILD_DIR" ]
then
    echo "Directory $CUR_DIR/$BUILD_DIR exists\n"
    echo "Deliting..."
    rm -R "$CUR_DIR/$BUILD_DIR"
    echo "Creating new $CUR_DIR/$BUILD_DIR"
    mkdir "$BUILD_DIR"
else
    echo "Creating $CUR_DIR/$BUILD_DIR"
    mkdir "$BUILD_DIR"
fi


cd $BUILD_DIR
#calling for cmake with CodeBlocks project generation
echo "cmake execution...."
echo "path to log: $CUR_DIR/CMake.log"
cmake ../ -G "CodeBlocks - Unix Makefiles" | tee "$CUR_DIR/CMake.log"
#building app
echo "make execution...."
echo "path to log: $CUR_DIR/Make.log" 
cmake --build . | tee "$CUR_DIR/Make.log"
#copying app to the src dir
cp "ConwayLifeGame" "../ConwayLifeGame"

